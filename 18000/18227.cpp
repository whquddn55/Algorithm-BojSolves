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
#define MAX_N 200005
#define MOD 1000000007

int n, c, m;
int tree[MAX_N * 4];

vector<int> adj[MAX_N];
int s[MAX_N];
int e[MAX_N];
int depth[MAX_N];
int dfsCnt = 0;

void update(int target, int value, int id = 1, int nodeLeft = 1, int nodeRight = n) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (target < nodeLeft || nodeRight < target) 
		return;
	if (nodeLeft == nodeRight) {
		tree[id] += value;
		return;
	}
	update(target, value, id * 2, nodeLeft, mid);
	update(target, value, id * 2 + 1, mid + 1, nodeRight);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int left, int right, int id = 1, int nodeLeft = 1, int nodeRight = n) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (right < nodeLeft || nodeRight < left)
		return 0;
	if (left <= nodeLeft && nodeRight <= right)
		return tree[id];
	return query(left, right, id * 2, nodeLeft, mid) + query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

void dfs(int here, int parent) {
	s[here] = ++dfsCnt;
	depth[here] = depth[parent] + 1;
	for (auto next : adj[here])
		if (next != parent)
			dfs(next, here);
	e[here] = dfsCnt;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n - 1; ++i) {
		int f, t;
		cin >> f>> t;
		adj[f].emplace_back(t);
		adj[t].emplace_back(f);
	}

	dfs(c, 0);

	cin >> m;
	while(m--) {
		int o;
		cin >> o;
		if (o == 1){
			int f;
			cin >> f;
			update(s[f], 1);
		}
		else {
			int f;
			cin >> f;
			cout << (ll)query(s[f], e[f]) * depth[f] << endl;
		}
	}

	return 0;
}
