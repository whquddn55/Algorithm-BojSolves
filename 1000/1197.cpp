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
vector<vector<pair<int, int> > > adj;

int kruskal() {
	vector<pair<int, pair<int, int > > > edges;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			edges.push_back(make_pair(adj[i][j].second, make_pair(i, adj[i][j].first)));

	sort(edges.begin(), edges.end());

	Nds set(n + 1);
	int ret = 0;
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].second.first, v = edges[i].second.second;
		int cost = edges[i].first;
		if (set.find(u) == set.find(v))
			continue;

		set.merge(u, v);
		ret += cost;
	}

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	while (m--) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back(make_pair(to, cost));
	}

	printf("%d\n", kruskal());

	return 0;
}