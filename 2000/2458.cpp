#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

struct Score {
	int s[3];
	int sum = 0;
};

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
	for (int i = 1; i <= n; i++)
		adj[i].resize(n + 1, INF);

	while (m--) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from][to] = 1;
	}

	floyd();

	int result = 0;
	for (int i = 1; i <= n; i++) {
		int n1 = 0, n2 = 0;
		
		for (int j = 1; j <= n; j++)
			if (adj[j][i] != INF)
				n1++;
		for (int j = 1; j <= n; j++)
			if (adj[i][j] != INF)
				n2++;

		if (n1 + n2 == n - 1)
			result++;
	}

	printf("%d\n", result);
	
	
	return 0;
}