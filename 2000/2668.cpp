#include <bits/stdc++.h>
using namespace std;

vector<int> adj;
vector<bool> visited;
vector<bool> v;
vector<int> result;

void get(int start, int end) {
	while (start != end && v[adj[start]]) {
		result.push_back(start);
		start = adj[start];
	}
	result.push_back(end);
}

void dfs(int here) {
	visited[here] = true;
	v[here] = true;
	 
	int there = adj[here];
	if (v[there]) 
		get(there, here);
	if (visited[there])
		return;

	dfs(there);
}

int main() {
	int n;
	cin >> n;

	adj.resize(n + 1);
	visited.resize(n + 1, false);
	v.resize(n + 1, false);
	for (int i = 0; i < n; i++)
		cin >> adj[i + 1];

	for (int i = 1; i <= n; i++)
		if (!visited[i]) {
			v.clear();
			v.resize(n + 1, false);
			dfs(i);
		}

	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}