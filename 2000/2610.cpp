#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<int> > adj;
vector<bool> visited;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 1; i <= n; i++)
		adj[i][i] = INF;
}

int bfs(int start) {
	queue<int> q;
	q.push(start);
	vector<int> visit;
	int minimum = INF;
	int ret;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (visited[here])
			continue;
		visited[here] = true;
		visit.push_back(here);

		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (adj[here][i] == INF)
				continue;

			tmp = max(tmp, adj[here][i]);
			if (visited[i])
				continue;

			q.push(i);
		}

		if (minimum >= tmp) {
			minimum = tmp;
			ret = here;
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 1; i <= n; i++)
		adj[i].resize(n + 1, INF);
	while (m--) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from][to] = 1;
		adj[to][from] = 1;
	}

	floyd();

	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		result.push_back(bfs(i));
	}
	sort(result.begin(), result.end());

	printf("%d\n", result.size());
	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);

	return 0;
}