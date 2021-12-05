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
#define MAX_N 8
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N][MAX_N];
vector<pii> vir;
int cnt;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[MAX_N][MAX_N];
int dfs(int hy, int hx) {
    visited[hy][hx] = true;
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = hy + dy[i];
        int nx = hx + dx[i];
        if (ny >= n || ny < 0 || nx >= m || nx < 0)
            continue;
        if (visited[ny][nx])
            continue;
        if (arr[ny][nx] != 0)
            continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) 
                vir.emplace_back(i, j);
            if (arr[i][j] == 1)
                ++cnt;
        }

    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
        if (arr[i / m][i % m] != 0)
            continue;
        arr[i / m][i % m] = 1;
        for (int j = i + 1; j < n * m; ++j) {
            if (arr[j / m][j % m] != 0)
                continue;
            arr[j / m][j % m] = 1;
            for (int k = j + 1; k < n * m; ++k) {
                if (arr[k / m][k % m] != 0)
                    continue;
                arr[k / m][k % m] = 1;

                memset(visited, 0, sizeof(visited));
                int temp = n * m - cnt - 3;
                for (auto e : vir) {
                    if (!visited[e.first][e.second])
                        temp -= dfs(e.first, e.second);
                }
                ans = max(ans, temp);

                arr[k / m][k % m] = 0;
            }
            arr[j / m][j % m] = 0;
        }
        arr[i / m][i % m] = 0;
    }
    cout << ans << endl;
    
    return 0;
}
