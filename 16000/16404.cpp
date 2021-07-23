#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
    os << pai.first << ' ' << pai.second;
    return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
    is >> pai.first >> pai.second;
    return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 100005
#define MOD 1000000007

int n, m;
int lazy[MAX_N * 4];
int tree[MAX_N * 4];
int dfscnt = 0;
int newIndex[MAX_N];
int endIndex[MAX_N];
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

void update(int left, int right, int val, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (left > nodeRight || right < nodeLeft)
		return;

	if (left <= nodeLeft && right >= nodeRight) {
		lazy[id] += val;
		return;
	}
	update(left, right, val, id * 2, nodeLeft, mid);
	update(left, right, val, id * 2 + 1, mid + 1, nodeRight);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (right < nodeLeft || left > nodeRight)
		return 0;
	if (left <= nodeLeft && right >= nodeRight)
		return tree[id];

	return query(left, right, id * 2, nodeLeft, mid) + query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

int dfs(int here) {
	newIndex[here] = dfscnt++;
	endIndex[newIndex[here]] = newIndex[here];
	for (auto next : adj[here])
		endIndex[newIndex[here]] = max(endIndex[newIndex[here]], dfs(next));
	return endIndex[newIndex[here]];
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		if (t == -1)
			continue;
		adj[t].emplace_back(i);
	}

	for (int i = 1; i <= n; ++i)
		if (!newIndex[i])
			dfs(i);


	while(m--) {
		int o;
		cin >> o;
		if (o == 1) {
			int i, w;
			cin >> i >> w;
			update(newIndex[i], endIndex[newIndex[i]], w);
		}
		else {
			int i;
			cin >> i;
 			cout << query(newIndex[i], newIndex[i]) << endl;
		}
	}

	return 0;
}

