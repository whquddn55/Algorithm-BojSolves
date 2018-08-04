#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100000

int n, m;
int lazy[MAX_N * 4];
int tree[MAX_N * 4];
int num[MAX_N];
int cnum[MAX_N];
int cnt = 0;

vector<int> adj[MAX_N];

void updateLazy(int id, int nodeLeft, int nodeRight) {
	if (lazy[id]) {
		tree[id] += (nodeRight - nodeLeft + 1) * lazy[id];

		if (nodeLeft != nodeRight) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
}

int update(int left, int right, int val,int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (left > nodeRight || right < nodeLeft)
		return tree[id];

	if (left <= nodeLeft && right >= nodeRight) {
		tree[id] += (nodeRight - nodeLeft + 1) * val;
		if (nodeLeft != nodeRight) {
			lazy[id * 2] += val;
			lazy[id * 2 + 1] += val;
		}
		return tree[id];
	}

	return tree[id] = update(left, right, val, id * 2, nodeLeft, mid) + update(left, right, val, id * 2 + 1, mid + 1, nodeRight);
}

int query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (right < nodeLeft || left > nodeRight)
		return 0;
	if (left <= nodeLeft && right >= nodeRight)
		return tree[id];

	return query(left, right, id * 2, nodeLeft, mid) + query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

int dfs(int here) {
	int c = 0;
	for (auto e : adj[here])
		c += dfs(e);
	num[here] = cnt++;
	cnum[here] = c;
	return c + 1;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		if (i == 0)
			continue;
		u--;
		adj[u].emplace_back(i);
	}
	dfs(0);
	while (m--) {
		int command;
		cin >> command;
		if (command == 1) {
			int u, value;
			cin >> u >> value;
			u--;
			update(num[u] - cnum[u], num[u], value);
		}
		else {
			int u;
			cin >> u;
			u--;
			cout << query(num[u], num[u]) << endl;
		}
	}

	return 0;
}
