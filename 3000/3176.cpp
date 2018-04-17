#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_NODE 100001
const int maxLevel = (int)floor(log2(MAX_NODE));

int maxDist[MAX_NODE][20];
int minDist[MAX_NODE][20];

int n, m; //  n : node 개수
int depth[MAX_NODE]; // 각 노드의 depth
int ac[MAX_NODE][20]; // 각 노드의 2^j번째 조상
vector<pii> adj[MAX_NODE]; // 인접 리스트

void getTree(int here, int parent, int cost) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;
	maxDist[here][0] = cost;
	minDist[here][0] = cost;

	for (int i = 1; i <= maxLevel; i++) {
		ac[here][i] = ac[ac[here][i - 1]][i - 1];
		maxDist[here][i] = max(maxDist[here][i - 1], maxDist[ac[here][i - 1]][i - 1]);
		minDist[here][i] = min(minDist[here][i - 1], minDist[ac[here][i - 1]][i - 1]);
	}

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i].first != parent)
			getTree(adj[here][i].first, here, adj[here][i].second);
}

pii get(int a, int b) {
	pii ret = { INF, 0 };
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b])
			swap(a, b);

		for (int i = maxLevel; i >= 0; i--)
			if (depth[a] <= depth[ac[b][i]]) {
				ret.first = min(ret.first, minDist[b][i]);
				ret.second = max(ret.second, maxDist[b][i]);
				b = ac[b][i];
			}
	}

	if (a != b) {
		for (int i = maxLevel; i >= 0; i--) {
			if (ac[a][i] != ac[b][i]) {
				ret.first = min({ ret.first, minDist[a][i], minDist[b][i] });
				ret.second = max({ ret.second, maxDist[a][i], maxDist[b][i] });
				a = ac[a][i];
				b = ac[b][i];
			}
		}
		ret.first = min({ ret.first, minDist[a][0], minDist[b][0] });
		ret.second = max({ ret.second, maxDist[a][0], maxDist[b][0] });
	}

	return ret;
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
	for (int i = 0; i < MAX_NODE; i++)
		fill(minDist[i], minDist[i] + 20, INF);

	getTree(1, 0, 0);
 
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		pii ret = get(a, b);
		cout << ret.first << ' ' << ret.second << endl;
	}

	return 0;
}
