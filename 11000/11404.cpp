#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m;
vector<vector<int> > adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	scanf("%d %d", &n, &m);

	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		adj[i].resize(n + 1, INF);
		adj[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][to] = min(adj[from][to], cost);
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", adj[i][j] >= INF ? 0 : adj[i][j]);
		printf("\n");
	}

	return 0;
}