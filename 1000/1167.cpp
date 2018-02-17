#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int v;
vector<vector<pii> > adj;

pii bfs(int start) {
	queue<pii> q;
	q.emplace(start, 0);
	vector<int> dist(v + 1, 0);

	while (!q.empty()) {
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (dist[here])
			continue;

		dist[here] = cost;

		for (const auto& pi : adj[here]) {
			if (dist[pi.first])
				continue;
			q.emplace(pi.first, pi.second + cost);
		}
	}
	dist[start] = 0;

	pii ret(-INF, 0);
	for (int i = 1; i <= v; i++)
		if (ret.first < dist[i]) {
			ret.first = dist[i];
			ret.second = i;
		}
	return ret;
}

int main() {
	scanf("%d", &v);
	adj.resize(v + 1);
	for (int i = 0; i < v; i++) {
		int from;
		scanf("%d", &from);
		while (true) {
			int to, cost;
			scanf("%d", &to);
			if (to == -1)
				break;
			scanf("%d", &cost);
			adj[from].emplace_back(to, cost);
		}
	}
	printf("%d\n", bfs(bfs(1).second).first);

	return 0;
}