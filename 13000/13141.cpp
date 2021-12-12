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
#define MAX_N 205
#define MOD 1'000'000'007

int n, m;
int dist[MAX_N][MAX_N];
vector<pair<pii, int>> edges;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < MAX_N;++i)
        for (int j = 0; j < MAX_N; ++j) {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    
    cin >> n >> m;
    while(m--){
        int s, e, l;
        cin >> s >> e >> l;
        edges.emplace_back(pii(s, e), l);
        dist[s][e] = min(dist[s][e], l);
        dist[e][s] = dist[s][e];
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int temp = 0;
        for (auto& e : edges) 
            temp = max(temp, dist[i][e.first.first] + dist[i][e.first.second] + e.second);
        ans = min(ans, temp);
    }

    cout << ans / 2 << '.' << (ans % 2 ? 5 : 0) << endl;
    
    return 0;
}
