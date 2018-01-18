#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX / 2

struct Nds {
	vector<int> parent;
	Nds(int n)
		: parent(n) {
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

		parent[u] = v;
	}
};

int n, m;
vector<vector<pair<int, int> > > adj;

int kruskal() {
	vector<pair<int, pair<int, int> > > edges; // first : cost, second.first : from, second.second : to
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			edges.push_back(make_pair(adj[i][j].second, make_pair(i, adj[i][j].first)));

	sort(edges.begin(), edges.end());
	
	Nds nds(n + 1);
	int ret = 0;
	int lastCost = 0;
	for (int i = 0; i < edges.size(); i++) {
		int from = edges[i].second.first, to = edges[i].second.second;
		int cost = edges[i].first;

		if (nds.find(from) == nds.find(to))
			continue;

		ret += cost;
		lastCost = cost;
		nds.merge(nds.find(from), nds.find(to));
	}
	return ret - lastCost;
}

int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);

		adj[from].push_back(make_pair(to, cost));
		adj[to].push_back(make_pair(from, cost));
	}

	printf("%d\n", kruskal());

	return 0;
}