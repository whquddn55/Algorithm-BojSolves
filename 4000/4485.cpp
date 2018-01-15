#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n;
vector<vector<int> > dist;
vector<vector<int> > graph;

/*
void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}*/


int dijkstra(int fromY, int fromX) {
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > pq;
	pq.push(make_pair(graph[fromY][fromX], make_pair(fromY, fromX)));
	dist[fromY][fromX] = graph[fromY][fromX];

	while (!pq.empty()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[y][x] < cost)
			continue;

		int dy[] = { 0, -1, 0, 1 };
		int dx[] = { -1, 0, 1, 0 };
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || nx >= n || ny < 0 || nx < 0)
				continue;

			int thereDist = cost + graph[ny][nx];
			if (thereDist < dist[ny][nx]) {
				dist[ny][nx] = thereDist;
				pq.push(make_pair(thereDist, make_pair(ny, nx)));
			}
		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	int cnt = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		graph.resize(n);
		dist.resize(n);
		for (int i = 0; i < n; i++) {
			graph[i].resize(n);
			dist[i].resize(n);
			fill(dist[i].begin(), dist[i].end(), INF);
			for (int j = 0; j < n; j++)
				scanf("%d", &graph[i][j]);
		}

		printf("Problem %d: %d\n", cnt++ ,dijkstra(0, 0));
	}

	return 0;
}