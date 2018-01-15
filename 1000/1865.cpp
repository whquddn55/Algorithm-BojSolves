#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, w;
vector<vector<pair<int, int> > >  adj;
vector<int> dist;

bool bellman(int start) {
	dist[start] = 0;
	bool updated;

	for (int i = 0; i < n; i++) {
		updated = false;
		for (int here = 1; here <= n; here++)
			for (int j = 0; j < adj[here].size(); j++) {
				int there = adj[here][j].first;
				int cost = adj[here][j].second;

				if (dist[there] > dist[here] + cost) {
					dist[there] = dist[here] + cost;
					updated = true;
				}
			}

		if (!updated)
			break;
	}
	if (updated)
		return false;
	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &w);

		dist.resize(n + 1);
		fill(dist.begin(), dist.end(), INF);
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			adj[from].push_back(make_pair(to, cost));
			adj[to].push_back(make_pair(from, cost));
		}
		for (int i = 0; i < w; i++) {
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			adj[from].push_back(make_pair(to, -cost));
		}
		bool check = bellman(1);
		printf("%s\n", check ? "NO" : "YES");
	}

	

	return 0;
}