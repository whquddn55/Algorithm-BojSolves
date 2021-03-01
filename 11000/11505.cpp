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

#define MAX_N 1000005
#define MOD 1000000007

int n, m, k;
int arr[MAX_N];
int tree[MAX_N * 4];

ll init(int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (nodeLeft == nodeRight) 
		return tree[node] = arr[nodeLeft];
	
	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = (init(node * 2, nodeLeft, mid) * init(node * 2 + 1, mid + 1, nodeRight)) % MOD;
}

ll update(int index, int value, int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (nodeLeft > index || nodeRight < index)
		return tree[node];
	if (nodeLeft == nodeRight)
		return tree[node] = value;

	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = (update(index, value, node * 2, nodeLeft, mid) * update(index, value, node * 2 + 1, mid + 1, nodeRight)) % MOD;
}

ll query(int l, int r, int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (nodeRight < l || r < nodeLeft)
		return 1;
	if (l <= nodeLeft && nodeRight <= r)
		return tree[node];

	int mid = (nodeLeft + nodeRight) / 2;
	return (query(l, r, node * 2, nodeLeft, mid) * query(l, r, node * 2 + 1, mid + 1, nodeRight)) % MOD;
}


int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	init();

	int q = m + k;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			update(b, c);
		}
		else {
			b--;
			c--;
			cout << query(b, c) << endl;
		}
	}

	return 0;
}