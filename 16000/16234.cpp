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
#define MOD2 1'000'000'009

int n, l, r;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool bfs(int sy, int sx, int value) {
    queue<pii> q;
    q.emplace(sy, sx);
    visited[sy][sx] = value;

    stack<pii> st;
    st.emplace(sy, sx);
    int sum = arr[sy][sx];
    while(q.size()) {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = hy + dy[i];
            int nx = hx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visited[ny][nx] == value) continue;
            if (l > abs(arr[ny][nx] - arr[hy][hx]) || abs(arr[ny][nx] - arr[hy][hx]) > r) continue;

            q.emplace(ny, nx);
            st.emplace(ny, nx);
            visited[ny][nx] = value;
            sum += arr[ny][nx];
        }
    }

    int sz = st.size();
    while(st.size()) {
        int hy = st.top().first;
        int hx = st.top().second;
        arr[hy][hx] = sum / sz;

        st.pop();
    }

    return sz != 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j]; 

    int ans = 0;
    memset(visited, -1, sizeof(visited));
    while(true) {
        bool res = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == ans) continue;
                res |= bfs(i, j, ans);
            }
        }
        if (res == false) break;


        ++ans;
    }

    cout << ans << endl;
    
    return 0;
}