#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 55
#define MOD 1'000'000'007

int n;
int arr[MAX_N][9];

vector<int> who;
bool visited[9];

int ans = 0;

void get() {
    if (who.size() == 9) {
        int whoIndex = 0;
        int score = 0;
        for (int i = 0; i < n; ++i) {
            int outCnt = 0;
            int home[3] = {0, };
            while(outCnt < 3) {
                int w = who[whoIndex];
                switch(arr[i][w]) {
                    case 0:
                        outCnt += 1;
                        break;
                    case 1:
                        score += home[2];
                        home[2] = home[1];
                        home[1] = home[0];
                        home[0] = 1;
                        break;
                    case 2:
                        score += home[2] + home[1];
                        home[2] = home[0];
                        home[1] = 1;
                        home[0] = 0;
                        break;
                    case 3:
                        score += home[2] + home[1] + home[0];
                        home[2] = 1;
                        home[1] = 0;
                        home[0] = 0;
                        break;
                    case 4:
                        score += home[2] + home[1] + home[0] + 1;
                        home[2] = 0;
                        home[1] = 0;
                        home[0] = 0;
                        break;
                }
                whoIndex = (whoIndex + 1) % 9;
            }
            
        }
        ans = max(ans, score);
        return;
    }

    if (who.size() == 3) {
        who.emplace_back(0);
        visited[0] = true;
        get();
        who.pop_back();
            visited[0] = false;
    } else {
        for (int i = 1; i < 9; ++i) {
            if (visited[i])
                continue;
            who.emplace_back(i);
            visited[i] = true;
            get();
            who.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> arr[i][j];

    get();
    cout << ans << endl;

    return 0;
}
