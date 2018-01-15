#include <bits/stdc++.h>
using namespace std;
#define INF 87654321

int v, e;
vector<vector<int> >  adj;

void floyd() {
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	scanf("%d %d", &v, &e);

	adj.resize(v + 1);
	for (int i = 1; i <= v; i++) {
		adj[i].resize(v + 1, INF);
		adj[i][i] = 0;
	}
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][to] = cost;
	}

	floyd();

	int result = INT_MAX;
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++) {
			if (i == j)
				continue;
			result = min(result, adj[i][j] + adj[j][i]);
		}
	printf("%d\n", result >= INF ? -1 : result);

	return 0;
}