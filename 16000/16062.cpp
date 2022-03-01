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
#define MAX_N 1005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n, m;
char arrayMap[MAX_N + 1][MAX_N * 2];
pii arr[MAX_N * 10];
int idx[MAX_N + 1][MAX_N * 2];
vector<int> adj[MAX_N * MAX_N * 2];

bool checkBoundary(int y, int x) {
    return y > 0 && y < n + 1 && x > 0 && x < 2 * m + 1;
}

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt = 0;
void dfs(int hy, int hx, int py, int px) {
    idx[hy][hx] = ++cnt;
    adj[idx[py][px]].push_back(idx[hy][hx]);
    //cout << pii(hy, hx) << endl;
    int ny = hy - 1;
    int nx = hx;
    if (checkBoundary(ny, nx) == true && arrayMap[ny][nx] == ' ' && (ny != py || nx != px)) {
        dfs(ny, nx, hy, hx);
    }

    ny = hy + 1;
    nx = hx;
    if (checkBoundary(ny, nx) == true && arrayMap[hy][nx] == ' ' && (ny != py || nx != px)) {
        dfs(ny, nx, hy, hx);
    }

    ny = hy;
    nx = hx + 2;
    if (checkBoundary(ny, nx) == true && arrayMap[ny][nx - 1] == ' ' && (ny != py || nx != px)) {
        dfs(ny, nx, hy, hx);
    }

    ny = hy;
    nx = hx - 2;
    if (checkBoundary(ny, nx) == true && arrayMap[ny][nx + 1] == ' ' && (ny != py || nx != px)) {
        dfs(ny, nx, hy, hx);
    }
}

int depth[MAX_N * MAX_N * 2]; // 각 노드의 depth
int ac[MAX_N * MAX_N * 2][25]; // 각 노드의 2^j번째 조상

const int maxLevel = (int)floor(log2(MAX_N * MAX_N * 2));

void getTree(int here, int parent) {
    depth[here] = depth[parent] + 1;
    ac[here][0] = parent;

    for (int i = 1; i <= maxLevel; i++)
        ac[here][i] = ac[ac[here][i - 1]][i - 1];

    for (int i = 0; i < adj[here].size(); i++)
        if (adj[here][i] != parent)
            getTree(adj[here][i], here);
}

int getLca(int a, int b) {
    int dist = depth[a] + depth[b];
    if (depth[a] != depth[b]) {
        if (depth[a] > depth[b])
            swap(a, b);

        for (int i = maxLevel; i >= 0; i--)
            if (depth[a] <= depth[ac[b][i]]) {
                b = ac[b][i];
            }
    }

    int lca = a;
    if (a != b) {
        for (int i = maxLevel; i >= 0; i--) {
            if (ac[a][i] != ac[b][i]) {
                a = ac[a][i];
                b = ac[b][i];
            }
            lca = ac[a][i];
        }
    }
    dist -= depth[lca] * 2;

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    cin.getline(arrayMap[0], 1, '\n');
    for (int i = 0; i < n + 1; ++i) {
        cin.getline(arrayMap[i], m * 2 + 5, '\n');
    }

    int sz;
    cin >> sz;
    for (int i = 0; i < sz; ++i) {
        cin >> arr[i];
        arr[i].second = arr[i].second * 2 - 1;
    }

    dfs(arr[0].first, arr[0].second, 0, 0);

    depth[0] = -1;
    getTree(1, 0);
    ll ans = 0;
    for (int i = 0; i < sz - 1; ++i) {
        ans += getLca(idx[arr[i].first][arr[i].second], idx[arr[i + 1].first][arr[i + 1].second]);
    }
    cout << ans << endl;
 
    return 0;
}
