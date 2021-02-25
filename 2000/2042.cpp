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

#define MAX_N 1000000
#define MOD 1000000007

int n, m, k;
ll arr[MAX_N];
ll tree[MAX_N * 4];

ll init(int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (nodeLeft == nodeRight)
		return tree[node] = arr[nodeLeft];

	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = init(node * 2, nodeLeft, mid) + init(node * 2 + 1, mid + 1, nodeRight);
}

ll update(int index, ll value, int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (index > nodeRight || index < nodeLeft)
		return tree[node];
	if (nodeLeft == nodeRight)
		return tree[node] = value;

	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = update(index, value, node * 2, nodeLeft, mid) + update(index, value, node * 2 + 1, mid + 1, nodeRight);
}

ll query(int l, int r, int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (l > nodeRight || r < nodeLeft)
		return 0;
	if (l <= nodeLeft && r >= nodeRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) / 2;
	return query(l, r, node * 2, nodeLeft, mid) + query(l, r, node * 2 + 1, mid + 1, nodeRight);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	init();
	for (int i = 0; i < m + k; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) 
			update(b - 1, c);
		else
			cout << query(b - 1, c - 1) << endl;
	}

	return 0;
}