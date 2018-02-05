#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)]
#define MOD 1000000000
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii> > adj;

struct Dset {
	vector<int> parent;
	vector<int> size;
	vector<int> rank;
	Dset(int n)
		: parent(n + 1), size(n + 1) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return;

		parent[u] = v;
		size[v] += size[u];
	}

	int get(int u) {
		return size[find(u)];
	}
};

int kruskal() {
	vector<pair<int, pii> > edges;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < adj[i].size(); j++) {
			edges.emplace_back(adj[i][j].second, make_pair(i, adj[i][j].first));
			sum += adj[i][j].second;
		}
	sort(edges.begin(), edges.end(), greater<pair<int, pii> >());

	Dset set(n);
	ll result = 0;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;

		if (set.find(u) == set.find(v)) {
			sum -= cost;
			continue;
		}

		result = (result + sum * ((ll)set.get(u)* set.get(v)) % MOD) % MOD;
		sum -= cost;
		set.merge(u, v);
	}

	return result % MOD;
}

int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	while (m--) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].emplace_back(to, cost);
	}

	printf("%d\n", kruskal());

	return 0;
}