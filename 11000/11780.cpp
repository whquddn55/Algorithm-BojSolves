#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m;
vector<vector<int> > adj;
vector<vector<int> > previous;
vector<int> path;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] =  adj[i][k] + adj[k][j];
					previous[i][j] = k;
				}
			}
}

void getPath(int from, int to) {
	if (previous[from][to] == -1) {
		path.push_back(from);
		if (from != to) 
			path.push_back(to);
	}
	else {
		int w = previous[from][to];
		getPath(from, w);
		path.pop_back();
		getPath(w, to);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	adj.resize(n + 1);
	previous.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		adj[i].resize(n + 1, INF);
		adj[i][i] = 0;
		previous[i].resize(n + 1, -1);
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			path.clear();
			getPath(i, j);
			if (path.size() == 1)
				printf("0\n");
			else {
				printf("%d ", path.size());
				for (int i = 0; i < path.size(); i++)
					printf("%d ", path[i]);
				printf("\n");
			}
		}
	}

	return 0;
}