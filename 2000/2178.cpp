#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101

struct Data {
	int y, x, cost;
	Data(int y, int x, int cost)
		:y(y), x(x), cost(cost) { }
};

int n, m;
char maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };
int bfs() {
	queue<Data> q;
	q.emplace(0, 0, 1);
	visited[0][0] = true;

	int ret = 1;
	while (!q.empty()) {
		int hereY = q.front().y;
		int hereX = q.front().x;
		int cost = q.front().cost;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (maze[nextY][nextX] == '0')
				continue;

			q.emplace(nextY, nextX, cost + 1);
			visited[nextY][nextX] = true;

			if (nextY == n - 1 && nextX == m - 1)
				ret = cost + 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];

	cout << bfs() << endl;

	return 0;
}
