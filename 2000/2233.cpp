#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_NODE 2001
const int maxLevel = (int)floor(log2(MAX_NODE));

int n; //  n : node 개수
int depth[MAX_NODE]; // 각 노드의 depth
int ac[MAX_NODE][20]; // 각 노드의 2^j번째 조상
vector<int> adj[MAX_NODE]; // 인접 리스트

int cnt = 0;
int idx = 0;
int x, y;
pii toErase;
string s;
pii num[MAX_NODE];

void getTree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;

	for (int i = 1; i <= maxLevel; i++)
		ac[here][i] = ac[ac[here][i - 1]][i - 1];

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i] != parent)
			getTree(adj[here][i], here);
}

void dfs(int here) {
	while (s[idx] != '1') {
		adj[here].push_back(++cnt);
		idx++;
		num[cnt].first = idx;
		dfs(cnt);

		if (idx >= s.size())
			return;
	}
	idx++;
	num[here].second = idx;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> s;
	cin >> x >> y;
	dfs(0);
	for (int i = 1; i <= n; i++) {
		if (num[i].first == x || num[i].second == x)
			toErase.first = i;
		if (num[i].first == y || num[i].second == y)
			toErase.second = i;
	}
    
	depth[0] = -1;
	getTree(1, 0);

	int a = toErase.first, b = toErase.second;
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
	cout << num[lca].first << ' ' << num[lca].second << endl;

	return 0;
}
