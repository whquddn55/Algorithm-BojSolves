#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 3)
#define endl '\n'

int n, m, q;
vector<int> vertexCost;
vector<pii> p;
vector<vector<int>> dist;
vector<vector<int>> ans;

void floyd() {
	for (int k = 1; k <= n; k++) {
		int t = p[k].second;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
				ans[i][j] = min(ans[i][j], dist[i][t] + dist[t][j] + max({ vertexCost[i], vertexCost[j], vertexCost[t] }));
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> q;
	vertexCost.resize(n + 1);
	p.resize(n + 1);
	p[0] = { -INF, -INF };
	for (int i = 1; i <= n; i++) {
		cin >> vertexCost[i];
		p[i] = pii(vertexCost[i], i);
	}

	dist.resize(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	while (m--) {
		int from, to, cost;
		cin >> from >> to >> cost;

		dist[from][to] = cost;
		dist[to][from] = cost;
	}

	sort(p.begin(), p.end());
	ans.resize(n + 1, vector<int>(n + 1, INF));
	floyd();

	while (q--) {
		int from, to;
		cin >> from >> to;
		cout << (ans[from][to] == INF ? -1 : ans[from][to]) << endl;
	}

	return 0;
}
