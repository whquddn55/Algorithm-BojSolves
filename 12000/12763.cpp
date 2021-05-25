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

#define INF (INT_MAX / 2)
#define MAX_N 105
#define MOD 1000000007

int n, t, m, l;
vector<pair<int, pii>> adj[MAX_N];

int dist[MAX_N][10005];
priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
int dijkstra() {
    for (int i = 0; i < n; ++ i)
        fill(dist[i], dist[i] + t + 1, INF);
    pq.emplace(pii(0, 0), 0);
    dist[0][0] = 0;

    while(pq.size()) {
        int here = pq.top().second;
        int hereCost = pq.top().first.first;
        int hereTime = pq.top().first.second;
        pq.pop();

        for (auto& e : adj[here]) {
            int nextCost = hereCost + e.second.second;
            int nextTime = hereTime + e.second.first;
            if (nextCost > m)
                continue;
            if (nextTime > t)
                continue;
            if (dist[e.first][nextTime] <= nextCost)
                continue;
            dist[e.first][nextTime] = nextCost;
            pq.emplace(pii(nextCost, nextTime), e.first);
        }
    }
    int ret = INF;
    for (int i = 0; i <= t; ++i)
        ret = min(ret, dist[n - 1][i]);
    if (ret == INF)
        return -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> t >> m >> l;
    while(l--) {
        int from, to, time, cost;
        cin >> from >> to >> time >> cost;
        --from;
        --to;
        adj[from].emplace_back(to, pii(time, cost));
        adj[to].emplace_back(from, pii(time, cost));
    }

    cout << dijkstra() << endl;
    
    return 0;
}