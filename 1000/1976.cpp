#include <bits/stdc++.h>
using namespace std;

struct Nds{
	vector<int> parent, rank;
	Nds(int n)
		: parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return;

		if (rank[u] > rank[v])
			swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v])
			rank[v]++;
	}
};

int n, m;
vector<vector<int> > adj;

int main() {
	scanf("%d %d", &n, &m);
	
	Nds set(n + 1);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		adj[i].resize(n + 1);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
			if (adj[i][j])
				set.merge(i, j);
		}
	}

	int temp;
	scanf("%d", &temp);
	m--;
	int first = set.find(temp);

	while (m--) {
		scanf("%d", &temp);
		int root = set.find(temp);

		if (root != first) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}