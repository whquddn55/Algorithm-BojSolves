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

int n, m;
vector<pll> adj[MAX_N];
int x, z;
int p;
int points[100];
vector<ll> dists[100];

vector<ll> spfa(int start) {
    queue<int> q;
    bool inQ[MAX_N] = {false};
    ll dist[MAX_N];
    fill_n(dist, MAX_N, LLONG_MAX / 4);
    q.emplace(start);
    inQ[start] = true;
    dist[start] = 0;

    while(q.size()) {
        int here = q.front();
        q.pop();
        inQ[here] = false;
        for (pii e: adj[here]) {
            int next = e.first;
            int cost = e.second;
            
            if (dist[here] + cost < dist[next]) {
                dist[next] = dist[here] + cost;
                if (!inQ[next]){
                    q.emplace(next);
                    inQ[next] = true;
                }
            }
        }
    }
    return vector<ll>(dist, dist + MAX_N);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    cin >> x >> z;

    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> points[i];
        dists[i] = spfa(points[i]);
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < p; ++j) {
            if (i == j)
                continue;
            for (int k = 0; k < p; ++k) {
                if ((j == k) || (i == k))
                    continue;
                ans = min(ans, dists[i][x] + dists[i][points[j]] + dists[k][points[j]] + dists[k][z]);
            }
        }

    cout << (ans >= LLONG_MAX / 4 ? -1 : ans) << endl;
    
    return 0;
}
