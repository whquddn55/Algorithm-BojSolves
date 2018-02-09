#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii> > graph; // first : 크기, second : 둘러쌓인 0의 개수
vector<vector<bool> > visited;

void bfs(int startY, int startX) {
	queue<pii> q;
	q.emplace(startY, startX);

	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();

		if (visited[hereY][hereX])
			continue;
		visited[hereY][hereX] = true;

		int dy[] = { 0, 1, -1, 0 };
		int dx[] = { -1, 0, 0, 1 };
		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (graph[nextY][nextX].first == 0) {
				graph[hereY][hereX].second++;
				continue;
			}
			if (visited[nextY][nextX])
				continue;

			q.emplace(nextY, nextX);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	graph.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		graph[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &graph[i][j].first);
	}

	int result = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			fill(visited[i].begin(), visited[i].end(), false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && graph[i][j].first != 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		
		if (cnt >= 2 || cnt == 0) {
			if (cnt == 0)
				result = 0;
			break;
		}
		result++;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				graph[i][j].first = graph[i][j].first - graph[i][j].second < 0 ? 0 : (graph[i][j].first - graph[i][j].second);
				graph[i][j].second = 0;
			}
	}

	printf("%d\n", result);



	return 0;
}