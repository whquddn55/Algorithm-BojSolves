#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_NODE 40001
int maxLevel = (int)floor(log2(MAX_NODE));

int n, m;
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int dist[MAX_NODE];

vector<pii> adj[MAX_NODE];

void getTree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;

	for (int i = 1; i <= maxLevel; i++)
		ac[here][i] = ac[ac[here][i - 1]][i - 1];

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i].first != parent)
			getTree(adj[here][i].first, here);
}

void bfs() {
	queue<int> q;
	bool visited[MAX_NODE] = { false, };
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			if (visited[adj[here][i].first])
				continue;

			q.push(adj[here][i].first);
			visited[adj[here][i].first] = true;
			dist[adj[here][i].first] = dist[here] +  adj[here][i].second;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].emplace_back(to, cost);
		adj[to].emplace_back(from, cost);
	}
	depth[0] = -1;
	getTree(1, 0);
	bfs();

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;

		int da = dist[a];
		int db = dist[b];

		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])
				swap(a, b);

			for (int i = maxLevel; i >= 0; i--) 
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
		}

		int lca = a;
		if (a != b) {
			for (int i = maxLevel; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}

		cout << abs(dist[lca] - da) + abs(dist[lca] - db) << endl;
	}


	return 0;
}
