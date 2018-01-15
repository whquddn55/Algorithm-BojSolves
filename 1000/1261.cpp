#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m;
vector<vector<int> > dist;
vector<vector<int> > graph;

int dijkstra(int fromY, int fromX) {
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > pq;
	pq.push(make_pair(0, make_pair(fromY, fromX)));
	dist[fromY][fromX] = 0;

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

			if (ny > n || nx > m || ny < 1 || nx < 1)
				continue;

			int thereDist = cost + graph[ny][nx];
			if (thereDist < dist[ny][nx]) {
				dist[ny][nx] = thereDist;
				pq.push(make_pair(thereDist, make_pair(ny, nx)));
			}
		}
	}

	return dist[n][m];
}

int main() {
	scanf("%d %d", &m, &n);

	graph.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 1; i <= n; i++)  {
		graph[i].resize(m + 1);
		dist[i].resize(m + 1, INF);
		for (int j = 1; j <= m; j++)
			scanf("%1d", &graph[i][j]);
	}

	cout << dijkstra(1, 1) << endl;

	return 0;
}