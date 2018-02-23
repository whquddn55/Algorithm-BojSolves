#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, k;
vector<vector<int>> graph;
queue<pii> q; // first : y, second : x
vector<vector<bool>> visited;

struct DisjointSet {
	vector<int> parent;
	vector<int> size;
	int maxsize = 1;

	void resize(int n) {
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u])
			return u;

		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return;
		size[v] += size[u];
		maxsize = max(maxsize, size[v]);
		parent[u] = v;
	}
};

DisjointSet dset;

void bfs(int size) {
	while (size--) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();

		int dy[] = { 0, -1, 1, 0 };
		int dx[] = { -1, 0, 0, 1 };
		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextX <= 0 || nextY <= 0 || nextX > n || nextY > n)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (graph[nextY][nextX] == -1) {
				graph[nextY][nextX] = graph[hereY][hereX];
				visited[nextY][nextX] = true;
				q.emplace(nextY, nextX);

				for (int j = 0; j < 4; j++) {
					int nnextY = nextY + dy[j];
					int nnextX = nextX + dx[j];

					if (nnextX <= 0 || nnextY <= 0 || nnextX > n || nnextY > n)
						continue;
					if (graph[nnextY][nnextX] != -1)
						dset.merge(graph[nnextY][nnextX], graph[nextY][nextX]);
				}
			}
			else {
				dset.merge(graph[nextY][nextX], graph[hereY][hereX]);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	graph.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		graph[i].resize(n + 1, -1);
		visited[i].resize(n + 1, false);
	}
	dset.resize(k);

	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[y][x] = i;
		visited[y][x] = true;
		q.emplace(y, x);

		int dy[] = { 0, -1, 1, 0 };
		int dx[] = { -1, 0, 0, 1 };
		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (nextX <= 0 || nextY <= 0 || nextX > n || nextY > n)
				continue;
			if (graph[nextY][nextX] != -1)
				dset.merge(graph[nextY][nextX], graph[y][x]);
		}
	}


	int result = 0;
	while (!q.empty()) {
		if (dset.maxsize == k)
			break;
		bfs(q.size());
		result++;
	}
	printf("%d\n", result);

	return 0;

}