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
#define MAX_N 10
#define MOD 1'000'000'007

int n, m, y;
int energy[MAX_N][MAX_N];
int add[MAX_N][MAX_N];
deque<int> tree[MAX_N][MAX_N];

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> add[i][j];

    while(m--) {
        int a, b, c;
        cin >> a >> b>> c;
        --a; --b;
        tree[a][b].emplace_back(c);
    }

for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            energy[i][j] = 5;

    while(y--) {
        /* 봄 */
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int newEnergy = 0;
                int sz = tree[i][j].size();
                for (int k = 0; k < sz; ++k) {
                    if (energy[i][j] - tree[i][j][k] < 0) {
                        newEnergy += tree[i][j][k] / 2;
                    } else {
                        energy[i][j] -= tree[i][j][k];
                        tree[i][j].emplace_back(tree[i][j][k] + 1);
                    }
                }
                while(sz--) {
                    tree[i][j].pop_front();
                }
                energy[i][j] += newEnergy;
            }
        }

        /* 가을 */
        int pushCnt[MAX_N][MAX_N] = { 0, };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < tree[i][j].size(); ++k) {
                    if (tree[i][j][k] % 5 == 0) {
                        for (int l = 0; l < 8; ++l) {
                            int ny = i + dy[l];
                            int nx = j + dx[l];
                            if (ny >= n || ny < 0 || nx >= n || nx < 0)
                                continue;
                            pushCnt[ny][nx]++;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                while(pushCnt[i][j]--) {
                    tree[i][j].emplace_front(1);
                }
            }
        }

        /* 겨울 */
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                energy[i][j] += add[i][j];
            }
        } 
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += tree[i][j].size();
        }
    }
    cout << ans << endl;

    return 0;
}
