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
 
#define MAX_N 1005

int n, m, k;
vector<pii> adj[MAX_N];

priority_queue<pii, vector<pii>, greater<pii>> pq;
priority_queue<int> dist[MAX_N];

void dijkstra() {
    pq.emplace(0, 0);
    dist[0].push(0);

    while(pq.size()) {
        int here = pq.top().second;
        int hereCost = pq.top().first;
        pq.pop();

        if (dist[here].top() < hereCost)
            continue;

        for(pii& nextP : adj[here]) {
            int next = nextP.first;
            int nextDist = hereCost + nextP.second;

            if(dist[next].size() < k || dist[next].top() >= nextDist) {
                if (dist[next].size() == k)
                    dist[next].pop();
                dist[next].push(nextDist);
                pq.emplace(nextDist, next);
            }
        }
    }
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    cin >> n >> m >> k;
    while(m--) {
        int f, t, d;
        cin >>f >> t >> d;
        --f;
        --t;
        adj[f].emplace_back(t, d);
    }

    dijkstra();

    for (int i = 0; i < n; ++i) {
        if (dist[i].size() < k)
            cout << -1 << endl;
        else 
            cout << dist[i].top() << endl;
    }
    
	return 0;
}