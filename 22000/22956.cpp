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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 1005

int n, m, q;
bool rained[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];
int parent[MAX_N * MAX_N];
pair<pii, pii> ans[MAX_N * MAX_N];

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[u] = v;
        if (ans[u] < ans[v])
            ans[v] = ans[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];
    for (int i = 0; i < n * m; ++i) {
        ans[i].first = {INF, INF};
        parent[i] = i;
    }
    
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        rained[a][b] = true;
        arr[a][b] -= c;
        int index = find(a * m + b);
        pii value = {arr[a][b], i};
        if (ans[index].first > value)
            ans[index] = {value, pii(a, b)};

        for (int j = 0; j < 4; ++j) {
            int ny = a + dy[j];
            int nx = b + dx[j];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (!rained[ny][nx])
                continue;
            int nindex = ny * m + nx;
            merge(nindex, index);
        }

        pii res = ans[find(a * m + b)].second;
        cout << res.first + 1 << ' ' << res.second + 1 << endl;
    }

    return 0;
}
