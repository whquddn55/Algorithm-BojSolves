#include <bits/stdc++.h>
using namespace std;

struct Point {
	int y, x;
	int minValue, maxValue;
	Point(int y, int x, int minValue, int maxValue)
		: y(y), x(x), minValue(minValue), maxValue(maxValue) { }
};

int n, m, v;
vector<vector<int> > adj;
vector<bool> visited;

void dfs(int here) {
	if (visited[here])
		return;

	visited[here] = true;
	cout << here << ' ';

	for (int i = 0; i < adj[here].size(); i++) 
		if (!visited[adj[here][i]])
			dfs(adj[here][i]);
}

void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (visited[here])
			continue;

		visited[here] = true;
		cout << here << ' ';

		for (int i = 0; i < adj[here].size(); i++) 
			if (!visited[adj[here][i]])
				q.push(adj[here][i]);
	}
}

int main() {
	cin >> n >> m >> v;

	adj.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	dfs(v);
	cout << endl;
	for (int i = 1; i <= n; i++)
		visited[i] = false;
	bfs(v);

	return 0;
}