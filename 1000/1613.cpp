#include <bits/stdc++.h>
using namespace std;
#define INF 999999999

struct Data {
	int from, cost;
	Data(int from, int cost)
		:from(from), cost(cost) { }
};

int n, k, s;
vector<vector<int> > adj;
vector<bool> visited;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		adj[i].resize(n + 1, INF);
		adj[i][i] = 0;
	}

	visited.resize(n + 1, false);
	for (int i = 0; i < k; i++) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}
	
	floyd();

	cin >> s;
	for (int i = 0; i < s; i++) {
		int from, to;
		cin >> from >> to;

		if (adj[from][to] != INF)
			cout << -1 << endl;
		else if (adj[to][from] != INF)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}