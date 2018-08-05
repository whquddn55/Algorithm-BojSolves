#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 1001

int n, p, k;
int dist[MAX_N][MAX_N];
vector<pii> adj[MAX_N];

void dijkstra() {
	for (int i = 0; i < MAX_N; i++)
		fill_n(dist[i], MAX_N, INF);

	priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
	pq.emplace(pii(0, 0), 0);
	dist[0][0] = 0;

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first.first;
		int t = pq.top().first.second;
		pq.pop();

		for (auto e : adj[here]) {
			if (dist[e.first][t] > max(cost, e.second)) {
				dist[e.first][t] = max(cost, e.second);
				pq.emplace(pii(max(cost, e.second), t), e.first);
			}
			if (t < k && dist[e.first][t + 1] > cost) {
				dist[e.first][t + 1] = cost;
				pq.emplace(pii(cost, t + 1), e.first);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> p >> k;
	while (p--) {
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	dijkstra();
	int ans = INF;
	for (int i = 0; i <= k; i++)
		ans = min(ans, dist[n - 1][i]);
	cout << (ans == INF ? -1 : ans) << endl;

	return 0;
}
