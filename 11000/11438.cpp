#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_NODE 100001
int maxLevel = (int)floor(log2(MAX_NODE));

int n, m;
int depth[MAX_NODE];
int ac[MAX_NODE][20];

vector<int> adj[MAX_NODE];

void getTree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;

	for (int i = 1; i <= maxLevel; i++)
		ac[here][i] = ac[ac[here][i - 1]][i - 1];

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i] != parent)
			getTree(adj[here][i], here);
}


int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	depth[0] = -1;
	getTree(1, 0);

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;

		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])
				swap(a, b);

			for (int i = maxLevel; i >= 0; i--) 
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
		}

		int ans = a;
		if (a != b) {
			for (int i = maxLevel; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				ans = ac[a][i];
			}
		}

		cout << ans << endl;
	}


	return 0;
}
