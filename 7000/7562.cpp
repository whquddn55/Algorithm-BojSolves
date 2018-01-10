#include <bits/stdc++.h>
using namespace std;

struct Point {
	int y, x;
	int cost;
	Point(int y, int x, int cost)
		: y(y), x(x), cost(cost) { }
};

int l;
int startY, startX;
int toY, toX;
vector<vector<int> > graph;
vector<vector<int> > visited;

int bfs() {
	queue<Point> q;
	q.push(Point(startY, startX, 0));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cost = q.front().cost;
		q.pop();

		if (visited[y][x])
			continue;

		visited[y][x] = true;
		if (y == toY && x == toX)
			return cost;

		int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
		int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= l || nx >= l || ny < 0 || nx < 0)
				continue;

			if (visited[ny][nx])
				continue;

			q.push(Point(ny, nx, cost + 1));

		}
	}
	return -1;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> l >> startY >> startX >> toY >> toX;
		visited.resize(l);
		for (int i = 0; i < l; i++) {
			visited[i].clear();
			visited[i].resize(l, false);
		}
		
		cout << bfs() << endl;
	}

	return 0;
}