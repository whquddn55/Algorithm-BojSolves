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

int bfs(int startY, int startX) {
	queue<Point> q;
	q.push(Point(startY, startX));

	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		if (visited[y][x])
			continue;

		visited[y][x] = true;
		cnt++;

		int dy[] = { 0, -1, 0, 1};
		int dx[] = { -1, 0, 1, 0};
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || nx >= m || ny < 0 || nx < 0)
				continue;

			if (visited[ny][nx] || graph[ny][nx] == 1)
				continue;

			q.push(Point(ny, nx));
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;

	graph.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		graph[i].resize(m, 0);
		visited[i].resize(m);
		fill(visited[i].begin(), visited[i].end(), false);
	}
	for (int j = 0; j < k; j++) {
		int fromX, fromY, toX, toY;
		cin >> fromX >> fromY >> toX >> toY;
		for (int r = (n - toY); r < (n - fromY); r++)
			for (int c = fromX; c < toX; c++)
				graph[r][c] = 1;
	}

	int cnt = 0;
	vector<int> results;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && graph[i][j] == 0) {
				cnt++;
				results.push_back(bfs(i, j));
			}
	cout << cnt << endl;
	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); i++)
		cout << results[i] << ' ';

	return 0;
}