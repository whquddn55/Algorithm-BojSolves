#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 501

int n, m;
int visited[MAX_N];
vector<int> adj[MAX_N];

bool isCycle = true;

void dfs(int here, int parent) {
	if (!isCycle)
		return;
	visited[here] = -1;

	for (auto next : adj[here]) {
		if (next == parent)
			continue;
		if (visited[next] == -1)
			isCycle = false;
		if (visited[next] == 0)
			dfs(next, here);
		if (!isCycle)
			return;
	}

	visited[here] = 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0)
			break;

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < MAX_N; i++)
			adj[i].clear();

		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (visited[i] == 0) {
				isCycle = true;
				dfs(i, -1);
				if (isCycle)
					ans++;
			}

		cout << "Case " << tc++ << ": ";
		if (ans == 0)
			cout << "No trees." << endl;
		else if (ans == 1)
			cout << "There is one tree." << endl;
		else 
			cout << "A forest of " << ans << " trees." << endl;
	}
	

	return 0;
}
