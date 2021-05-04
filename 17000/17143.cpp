#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100

struct Data {
    int r, c, s, d, z;
    bool alive = true;
    bool operator<(const Data& b) const {
        if (r == b.r)
            return c < b.c;
        return r < b.r;
    }
};

int r, c;
int m;
Data shark[MAX_N * MAX_N];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> r >> c >> m;
    for (int i = 0; i < m; ++i) {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        --shark[i].r;
        --shark[i].c;
        --shark[i].d;
    }
    
    int sum = 0;
    for (int i = 0; i < c; ++i) {
        int index = -1;
        int minRow = INF;
        for (int j = 0; j < m; ++j)
            if (shark[j].c == i && minRow > shark[j].r && shark[j].alive) {
                minRow = shark[j].r;
                index = j;
            }
        if (index != -1) {
            sum += shark[index].z;
            shark[index].alive = false;
        }

        for (int j = 0; j < m; ++j) {
            if (shark[j].alive) {
                shark[j].r += shark[j].s * dy[shark[j].d];
                shark[j].c += shark[j].s * dx[shark[j].d];
                while(!(shark[j].r >= 0 && shark[j].r < r && shark[j].c >= 0 && shark[j].c < c)) {
                    if (shark[j].r < 0) {
                        shark[j].r = -shark[j].r;
                        shark[j].d = 1;
                    }
                    else if (shark[j].c < 0) {
                        shark[j].c = -shark[j].c;
                        shark[j].d = 2;
                    }
                    else if (shark[j].r >= r) {
                        shark[j].r = 2 * r - shark[j].r - 2;
                        shark[j].d = 0;
                    }
                    else if (shark[j].c >= c) {
                        shark[j].c = 2 * c - shark[j].c - 2;
                        shark[j].d = 3;
                    }
                }
            }
        }

        sort(shark, shark + m);
        for (int j = 0; j < m; ++j) {
            int startIndex = lower_bound(shark, shark + m, shark[j]) - shark;
            int endIndex = upper_bound(shark, shark + m, shark[j]) - shark;

            int maxIndex = -1;
            int maxValue = 0;
            for (int k = startIndex; k < endIndex; ++k) {
                if (shark[k].alive && maxValue < shark[k].z) {
                    maxValue = shark[k].z;
                    maxIndex = k;
                }
            }
            for (int k = startIndex; k < endIndex; ++k)
                if (k != maxIndex)
                    shark[k].alive = false;
        }
    }
    cout << sum << endl;
	return 0;
}
