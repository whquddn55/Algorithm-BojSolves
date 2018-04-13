#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 200001

struct Edge {
	int from, to, cost;
	bool checked = false;

	bool operator<(const Edge& other) {
		return cost < other.cost;
	}
};

struct DisjointSet {
	int parent[MAX_SIZE];
	DisjointSet() {
		for (int i = 0; i < MAX_SIZE; i++)
			parent[i] = i;
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
	}
};

int n, m;
Edge edges[MAX_SIZE];

void kruskal() {
	sort(edges, edges + m);

	DisjointSet dset;

	for (int i = 0; i < m; i++) {
		int u = dset.find(edges[i].from);
		int v = dset.find(edges[i].to);
		if (u != v) {
			dset.merge(u, v);
			edges[i].checked = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while (true) {
		cin >> n >> m;
		if (n == 0)
			break;

		for (int i = 0; i < m; i++) {
			cin >> edges[i].from >> edges[i].to >> edges[i].cost;
			edges[i].checked = false;
		}
		kruskal();

		int ans = 0;
		for (int i = 0; i < m; i++)
			if (!edges[i].checked)
				ans += edges[i].cost;

		cout << ans << endl;
	}

	return 0;
}
