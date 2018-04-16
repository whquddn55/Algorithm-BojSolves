#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_NODE 100001
const int maxLevel = (int)floor(log2(MAX_NODE));

int n, m; //  n : node 개수
int depth[MAX_NODE]; // 각 노드의 depth
int ac[MAX_NODE][20]; // 각 노드의 2^j번째 조상
vector<int> adj[MAX_NODE]; // 인접 리스트

void getTree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;

	for (int i = 1; i <= maxLevel; i++)
		ac[here][i] = ac[ac[here][i - 1]][i - 1];

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i] != parent)
			getTree(adj[here][i], here);
}

int getLca(int a, int b) {
	int ret = 0;
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b])
			swap(a, b);

		for (int i = maxLevel; i >= 0; i--)
			if (depth[a] <= depth[ac[b][i]]) {
				b = ac[b][i];
				ret += pow(2, i);
			}
	}

	int lca = a;
	if (a != b) {
		for (int i = maxLevel; i >= 0; i--) {
			if (ac[a][i] != ac[b][i]) {
				a = ac[a][i];
				b = ac[b][i];
				ret += pow(2, i + 1);
			}
			lca = ac[a][i];
		}
	}

	return ret + ( a != b && ac[a][0] == ac[b][0] ? 2 : 0);
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
	int prv = 1;
	int ans = 0;
	while (m--) {
		int a;
		cin >> a;
		ans += getLca(a, prv);
		prv = a;
	}
	cout << ans << endl;

	return 0;
}
