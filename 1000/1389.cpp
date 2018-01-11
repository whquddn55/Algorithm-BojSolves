#include <bits/stdc++.h>
using namespace std;

struct Data {
	int here;
	int cost;
	Data(int here, int cost)
		: here(here), cost(cost) { }
};

int n, m;
vector<vector<int> > adj;
vector<int> visited;

int bfs(int start) {
	queue<Data> q;
	q.push(Data(start, 0));

	int result = 0;
	while (!q.empty()) {
		int here = q.front().here;
		int cost = q.front().cost;
		q.pop();

		if (visited[here])
			continue;

		visited[here] = true;
		result += cost;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];

			if (visited[there])
				continue;

			q.push(Data(there, cost + 1));
		}
	}

	return result;
}

int main() {
	cin >> n >> m;

	adj.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	int minValue = INT_MAX;
	int result;
	for (int i = 1; i <= n; i++) {
		fill(visited.begin(), visited.end(), false);
		int value = bfs(i);
		if (minValue > value) {
			minValue = value;
			result = i;
		}
	}
	cout << result << endl;

	return 0;
}