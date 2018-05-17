#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n, m;
int s, e;
int dist[MAX_N];
vector<pii> adj[MAX_N];

void bfs() {
	priority_queue<pii> q;
	q.emplace(INF, s);
	dist[s] = 0;

	while (!q.empty()) {
		int here = q.top().second;
		int hereCost = q.top().first;
		q.pop();
		
		for (pii v : adj[here]) {
			int next = v.first;
			int nextCost = min(hereCost, v.second);

			if (dist[next] < nextCost) {
				q.emplace(nextCost, next);
				dist[next] = nextCost;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	cin >> s >> e;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	bfs();
	cout << dist[e] << endl;

	return 0;
}
