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
#define MAX_N 100005
#define MOD 1000000

int n, m, l, u;
vector<pair<pii, int>> adj[MAX_N];
int dist[MAX_N];

int dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0);
    fill_n(dist, MAX_N, INF);
    dist[0] = 0;

    while(pq.size()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dist[here])
            continue;

        for (pair<pii, int>& e : adj[here]) {
            int nxt = e.first.first;
            int nxtCost = cost + e.first.second;

            if (dist[nxt] < nxtCost)
                continue;
            dist[nxt] = nxtCost;
            pq.emplace(nxtCost, nxt);
        }
    }

    bool flag[MAX_N] = {0, };
    for (int i = 0; i < n; ++i)
        if (dist[i] < u) {
            for (pair<pii, int>& e : adj[i])
                flag[e.second] = true;
        }

    
    return accumulate(flag, flag + MAX_N, 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> l >> u;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(pii(b, c * 2), m);
        adj[b].emplace_back(pii(a, c * 2), m);
    }

    cout << dijkstra() << endl;
    
    return 0;
}
