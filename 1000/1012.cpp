#include <bits/stdc++.h>
using namespace std;

struct Point {
	int y, x;
	Point(int y, int x)
		: y(y), x(x) { }
};

int n, m, k;
vector<vector<bool> > visited;
vector<vector<int> > graph;

void bfs(int startY, int startX) {
	queue<Point> q;
	q.push(Point(startY, startX));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		if (visited[y][x])
			continue;

		visited[y][x] = true;

		int dy[] = { 0, -1, 0, 1};
		int dx[] = { -1, 0, 1, 0};
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || nx >= m || ny < 0 || nx < 0)
				continue;

			if (visited[ny][nx] || graph[ny][nx] == 0)
				continue;

			q.push(Point(ny, nx));
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> m >> n >> k;

		graph.resize(n);
		visited.resize(n);
		for (int i = 0; i < n; i++) {
			graph[i].resize(m);
			visited[i].resize(m);
			fill(visited[i].begin(), visited[i].end(), false);
			fill(graph[i].begin(), graph[i].end(), 0);
		}
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			graph[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visited[i][j] && graph[i][j] == 1) {
					cnt++;
					bfs(i, j);
				}
		cout << cnt << endl;
	}

	return 0;
}