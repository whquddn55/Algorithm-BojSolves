#include <bits/stdc++.h>
using namespace std;
#define INF 999999999

enum TYPE {WATER, S};

struct Data {
	int y, x, cost;
	TYPE type;
	Data(int y, int x, int cost, TYPE type)
		:y(y), x(x), cost(cost), type(type) { }
};

int r, c;
vector<vector<char> > graph;
vector<vector<bool> > visited;

int bfs() {
	queue<Data> q;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (graph[i][j] == '*') {
				q.push(Data(i, j, 0, WATER));
				graph[i][j] = '.';
			}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (graph[i][j] == 'S') {
				q.push(Data(i, j, 0, S));
				graph[i][j] = '.';
			}

	while (!q.empty()) {
		int hereY = q.front().y;
		int hereX = q.front().x;
		int cost = q.front().cost;
		TYPE type = q.front().type;
		q.pop();

		if (type == S) {
			if (visited[hereY][hereX])
				continue;
			if (graph[hereY][hereX] == '*')
				continue;
			visited[hereY][hereX] = true;

			if (graph[hereY][hereX] == 'D')
				return cost;
		}
		else {
			if (graph[hereY][hereX] == '.')
				graph[hereY][hereX] = '*';
			else
				continue;
		}

		int dy[] = { 0, -1, 0, 1 };
		int dx[] = { -1, 0, 1, 0 };
		for (int i = 0; i < 4; i++) {
			int ny = hereY + dy[i];
			int nx = hereX + dx[i];

			if (ny >= r || nx >= c || ny < 0 || nx < 0)
				continue;
			if (graph[ny][nx] == 'X')
				continue;
			if (graph[ny][nx] == '*')
				continue;
			if (visited[ny][nx])
				continue;
			

			q.push(Data(ny, nx, cost + 1, type));
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> r >> c;
	graph.resize(r);
	visited.resize(r);
	for (int i = 0; i < r; i++) {
		graph[i].resize(c);
		visited[i].resize(c);
		for (int j = 0; j < c; j++)
			cin >> graph[i][j];
	}

	int result = bfs();
	if (result == -1)
		cout << "KAKTUS" << endl;
	else
		cout << result << endl;

	return 0;
}