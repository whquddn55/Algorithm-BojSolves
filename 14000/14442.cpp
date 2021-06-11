#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
    os << pai.first << ' ' << pai.second;
    return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
    is >> pai.first >> pai.second;
    return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 1005
#define MOD 9901

int n, m, k;
char arr[MAX_N][MAX_N];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cntK[MAX_N][MAX_N];
bool inQ[MAX_N][MAX_N];
queue<pii> q;
int bfs() {
    for (int i = 0; i < n; ++i)
        fill(cntK[i], cntK[i] + m, INF);
    q.emplace(0, 0);
    cntK[0][0] = 0;

    int ret = 0;
    while(q.size()) {
        ++ret;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            int hereY = q.front().first;
            int hereX = q.front().second;
            q.pop();
            inQ[hereY][hereX] = false;

            if (hereY == n - 1 && hereX == m - 1)
                return ret;

            for (int i = 0; i < 4; ++i) {
                int nextY = hereY + dy[i];
                int nextX = hereX + dx[i];
                int nextK = cntK[hereY][hereX];

                if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
                    continue;
                if (arr[nextY][nextX]) {
                    if (nextK == k)
                        continue;
                    ++nextK;
                }

                if (cntK[nextY][nextX] > nextK) {
                    cntK[nextY][nextX] = nextK;
                    if (!inQ[nextY][nextX]) {
                        q.emplace(nextY, nextX);
                        inQ[nextY][nextX] = true;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            arr[i][j] -='0';
        }

    cout << bfs() << endl;

    return 0;
}