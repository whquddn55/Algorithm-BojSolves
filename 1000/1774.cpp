#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::make_pair;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
vector<pii> arr;
vector<vector<double>> dist;

struct DisjointSet{
	vector<int> parent;
	DisjointSet(int n)
		:parent(n) {
		for (int i = 0; i < n; i++)
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

double kruskal() {
	double ret = 0;
	vector<pair<double, pii>> edges;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			edges.emplace_back(dist[i][j], make_pair(i, j));
	sort(edges.begin(), edges.end());

	DisjointSet dset(n);
	for (int i = 0; i < edges.size(); i++) {
		double cost = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;

		if (dset.find(from) == dset.find(to))
			continue;

		ret += cost;
		dset.merge(from, to);
	}

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	dist.resize(n);
	for (int i = 0; i < n; i++)
		dist[i].resize(n);

	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = sqrt((long long)(arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (long long)(arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));

	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		from--; to--;
		dist[from][to] = dist[to][from] = 0.0;
	}

	printf("%.2lf\n", kruskal());

	return 0;
}