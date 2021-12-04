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
#define MAX_N 105
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N][MAX_N];
int remain;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                remain++;
        }

    int ans = 0;
    while (remain) {
        queue<pii> q;
        int cnt[MAX_N][MAX_N] = {0, };
        bool visited[MAX_N][MAX_N] = {false, };
        q.emplace(0, 0);
        visited[0][0] = true;
        while(q.size()) {
            int hy = q.front().first;
            int hx = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int ny = hy + dy[i];
                int nx = hx + dx[i];
                if (ny >= n || ny < 0 || nx >= m || nx < 0)
                    continue;
                if (visited[ny][nx])
                    continue;
                if (arr[ny][nx] == 0) {
                    q.emplace(ny, nx);
                    visited[ny][nx] = true;
                } else {
                    cnt[ny][nx]++;
                }
                
            }
        } 

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (cnt[i][j] >= 2) {
                    arr[i][j] = 0;
                    --remain;
                }
            }
        ++ans;
    }
    cout << ans << endl;
    
    return 0;
}
