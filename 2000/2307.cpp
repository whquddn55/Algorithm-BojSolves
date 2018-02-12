#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii> > adj;
vector<int> dist;
vector<int> previous;
vector<pii> path;

void dijkstra(pii exclude) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.emplace(0, 1);
	dist.resize(n + 1, INF);
	previous.resize(n + 1);
	for (int i = 0; i <= n; i++)
		previous[i] = i;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int nextCost = adj[here][i].second + cost;

			if ((exclude.first == next && exclude.second == here) || (exclude.first == here && exclude.second == next))
				continue;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				previous[next] = here;
				pq.emplace(nextCost, next);
			}
		}
	}
	dist[1] = 0;
	previous[1] = 1;
}

void getPath(int here) {
	if (previous[here] == here) 
		return;

	path.emplace_back(here, previous[here]);
	
	getPath(previous[here]);
}

int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	while (m--) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].emplace_back(to, cost);
		adj[to].emplace_back(from, cost);
	}

	dijkstra(pii(0, 0));
	getPath(n);
	
	int minCost = dist[n];
	int result = 0;
	for (int i = 0; i < path.size(); i++) {
		dist.clear();
		dijkstra(path[i]);
		if (dist[n] == INF) {
			result = -1;
			break;
		}
		result = max(result, dist[n] - minCost);
	}
	printf("%d\n", result);
	
	


	return 0;
}