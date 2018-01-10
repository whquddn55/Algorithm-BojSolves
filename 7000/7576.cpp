#include <bits/stdc++.h>
using namespace std;

struct Point {
	int y, x;
	int day;
	Point(int y, int x, int day)
		: y(y), x(x), day(day) { }
};

int n, m;
vector<vector<int> > adj;
vector<vector<int> > visited;
vector<Point> tomato;

int bfs() {
	queue<Point> q;
	for (int i = 0; i < tomato.size(); i++)
		q.push(tomato[i]);

	int result = 0;
	while (!q.empty()) {
		int hereY = q.front().y;
		int hereX = q.front().x;
		int day = q.front().day;
		q.pop();

		if (visited[hereY][hereX])
			continue;

		visited[hereY][hereX] = true;
		adj[hereY][hereX] = 1;
		result = max(result, day);

		int dy[] = { 0, -1, 0, 1 };
		int dx[] = { -1, 0, 1, 0 };
		for (int i = 0; i < 4; i++) {
			int ny = hereY + dy[i];
			int nx = hereX + dx[i];

			if (ny >= n || nx >= m || ny < 0 || nx < 0)
				continue;

			if (visited[ny][nx] || adj[ny][nx] == -1)
				continue;

			q.push(Point(ny, nx, day + 1));

		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (adj[i][j] == 0)
				return -1;
	return result;
}

int main() {
	cin >> m >> n;

	adj.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		adj[i].resize(m);
		visited[i].resize(m, false);
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 1)
				tomato.push_back(Point(i, j, 0));
		}
	}
	cout << bfs() << endl;

	return 0;
}