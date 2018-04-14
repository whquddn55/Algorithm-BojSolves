#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101

struct Edge {
	int from, to;
	double dist;
	Edge(int from, int to, double dist)
		: from(from), to(to), dist(dist) { }
	bool operator<(const Edge& other) {
		return dist < other.dist;
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

int n;
pair<double, double> arr[MAX_SIZE];
vector<Edge> edges;

double kruskal() {
	sort(edges.begin(), edges.end());

	DisjointSet dSet;
	double ans = 0;

	for (int i = 0; i < edges.size(); i++) {
		int u = dSet.find(edges[i].from);
		int v = dSet.find(edges[i].to);
		if (u == v)
			continue;

		ans += edges[i].dist;
		dSet.merge(u, v);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	cout << fixed;
	cout.precision(2);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if (i != j)
				edges.emplace_back(i, j, sqrt((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second)));
		
	cout << kruskal() << endl;

	return 0;
}
