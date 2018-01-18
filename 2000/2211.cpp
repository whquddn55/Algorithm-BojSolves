#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX / 2

int n, m;
vector<vector<pair<int, int> > > adj;
vector<int> dist;
vector<int> previous;

vector<vector<bool> > visited;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // first : cost, second = vertex
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	previous[1] = 1;

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[here] < cost)
			continue;
		
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int thereDist = adj[here][i].second;

			if (cost + thereDist >= dist[there])
				continue;

			dist[there] = cost + thereDist;
			previous[there] = here;
			pq.push(make_pair(dist[there], there));
		}
	}
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
		adj[to].push_back(make_pair(from, cost));
	}

	dijkstra();

	visited.resize(n + 1);
	for (int i = 1; i <= n; i++)
		visited[i].resize(n + 1, false);

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		int here = previous[i];
		int before = i;
		while (before != 1) {
			if (!visited[here][before]) {
				visited[here][before] = true;
				cnt++;
			}
			before = here;
			here = previous[here];
		}
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (visited[i][j])
				printf("%d %d\n", i, j);

	return 0;
}