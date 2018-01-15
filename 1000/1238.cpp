#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, x, m;
vector<vector<int> > adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	scanf("%d %d %d", &n, &m, &x);

	adj.resize(n + 1);
	for (int i = 1; i < n + 1; i++) {
		adj[i].resize(n + 1, INF);
		adj[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][to] = cost;
	}

	floyd();
	
	int result = 0;
	for (int i = 1; i <= n; i++) 
		result = max(result, adj[i][x] + adj[x][i]);

	cout << result << endl;

	return 0;
}