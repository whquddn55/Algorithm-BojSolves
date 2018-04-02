#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 1002

int n, m;
int visited[MAX_V];
int b[MAX_V];
vector<int> adj[MAX_V];

int dfs(int& here) {
	if (visited[here] == 2)
		return 0;
	visited[here]++;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!b[there]) {
			b[there] = here;
			return true;
		}
	}
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (dfs(b[there])) {
			b[there] = here;
			return true;
		}
	}

	return 0;
}

int bmatch() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + MAX_V, 0);
		while (dfs(i))
			ret++;
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int sz;
		cin >> sz;
		while (sz--) {
			int to;
			cin >> to;
			adj[i].push_back(to);
		}
	}

	cout << bmatch() << endl;
	return 0;
}
