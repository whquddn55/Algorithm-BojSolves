#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m;
vector<int> previous;
vector<int> dist;
vector<vector<pair<int, int> > > adj;

int dijkstra(int from, int to) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, from));
	dist[from] = 0;

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int nextCost = adj[here][i].second + cost;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push(make_pair(nextCost, next));
				previous[next] = here;
			}
		}
	}

	return dist[to];
}

int main() {
	scanf("%d %d", &n, &m);

	adj.resize(n + 1);
	dist.resize(n + 1, INF);
	previous.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back(make_pair(to, cost));
	}

	int from, to;
	scanf("%d %d", &from, &to);
	printf("%d\n", dijkstra(from, to));

	stack<int> result;
	int vertex = to;
	while (vertex != from) {
		result.push(vertex);
		vertex = previous[vertex];
	}
	result.push(from);

	int size = result.size();
	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d ", result.top());
		result.pop();
	}
	printf("\n");

	return 0;
}