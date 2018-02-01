#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

struct Point {
	int x, y, z;
	int day;
	Point(int z, int y, int x, int day)
		:x(x), y(y), z(z), day(day) { }
};

int m, n, h;
vector<vector<vector<int > > > arr;

int bfs() {
	queue<Point> q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (arr[i][j][k] == 1) 
					q.push(Point(i, j, k, 0));
				

	int cost = 0;
	vector<vector<vector<bool> > > visited;
	visited.resize(h);
	for (int i = 0; i < h; i++) {
		visited[i].resize(n);
		for (int j = 0; j < n; j++)
			visited[i][j].resize(m, false);
	}
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		int day = q.front().day;
		q.pop();

		if (visited[z][y][x])
			continue;

		int dz[] = { 0, 0, 0, 0, 1, -1 };
		int dy[] = { 0, -1, 0, 1, 0, 0 };
		int dx[] = { -1, 0, 1, 0, 0, 0 };

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (nz >= h || nz < 0 || ny >= n || ny < 0 || nx >= m || nx < 0)
				continue;
			if (arr[nz][ny][nx] != 0)
				continue;
			if (visited[z][y][x])
				continue;

			q.emplace(nz, ny, nx, day + 1);
			arr[nz][ny][nx] = 1;
			cost = max(cost, day + 1);
		}

	}
	return cost;
}

int main() {
	scanf("%d %d %d", &m, &n, &h);
	arr.resize(h);
	for (int i = 0; i < h; i++) {
		arr[i].resize(n);
		for (int j = 0; j < n; j++)
			arr[i][j].resize(m);
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				scanf("%d", &arr[i][j][k]);
	
	int result = bfs();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (arr[i][j][k] == 0)
					result = -1;
	printf("%d\n", result);
	

	return 0;
}