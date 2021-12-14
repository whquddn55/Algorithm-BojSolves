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
#define MAX_N 100005
#define MOD 1'000'000'007

int n, r, q;
vector<int> adj[MAX_N];
int dp[MAX_N];

void dfs(int here, int parent) {
    int& ret = dp[here];

    ret = 1;
    for (int nxt : adj[here]) {
        if (nxt == parent)
            continue;
        dfs(nxt, here);
        ret += dp[nxt];
    }
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(r, 0);

    while(q--) {
        int u ;
        cin >> u;
        cout << dp[u] << endl;
    }
    
    return 0;
}
