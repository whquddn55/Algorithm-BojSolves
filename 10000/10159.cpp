#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector < vector<int> >adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] =  min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 1; i < n + 1; i++) {
		adj[i].resize(n + 1, INF);
		adj[i][i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from][to] = 1;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) 
			if (adj[i][j] == INF && adj[j][i] == INF)
				cnt++;
		printf("%d\n", cnt);
	}
	

	return 0;
}