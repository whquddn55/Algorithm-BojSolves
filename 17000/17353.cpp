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
#define MAX_N 500005
#define MOD 1000000007

int n;
int arr[MAX_N];
ll tree[MAX_N * 4];
pll lazy[MAX_N * 4];

void updateLazy(int nodeLeft, int nodeRight, int id) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (lazy[id].first) {
		tree[id] += lazy[id].first;
		if (nodeLeft != nodeRight) {
			lazy[id * 2].first += lazy[id].first; 
			lazy[id * 2].second += lazy[id].second;
			lazy[id * 2 + 1].first += (mid - nodeLeft + 1) * lazy[id].second + lazy[id].first;
			lazy[id * 2 + 1].second += lazy[id].second;
		}
		lazy[id] = {0, 0};
	}
}

void init(int nodeLeft = 1, int nodeRight = n, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight) {
		tree[id] = arr[nodeLeft];
		return;
	}
	init(nodeLeft, mid, id * 2);
	init(mid + 1, nodeRight, id * 2 + 1);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll update(int l, int r, int value, int nodeLeft = 1, int nodeRight = n, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (r < nodeLeft || nodeRight < l)
		return 0;
	updateLazy(nodeLeft, nodeRight, id);
	if (l <= nodeLeft && nodeRight <= r) {
		lazy[id].first += value;
		lazy[id].second += 1;
		return nodeRight - nodeLeft + 1;
	} 
	ll prv = update(l, r, value, nodeLeft, mid, id * 2);
	prv += update(l, r, prv + value, mid + 1, nodeRight, id * 2 + 1);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
	return prv;
}

ll query(int a, int nodeLeft = 1, int nodeRight = n, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (a < nodeLeft || nodeRight < a)
		return 0;
	updateLazy(nodeLeft, nodeRight, id);
	if (nodeLeft == nodeRight)
		return tree[id];
	return query(a, nodeLeft, mid, id * 2) + query(a, mid + 1, nodeRight, id * 2 + 1); 
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	init();
	
	int m;
	cin >> m;
	while(m--) {
		int c;
		cin >> c;
		if (c == 1) {
			int l, r;
			cin >> l >> r;
			update(l, r, 1);
		}
		else {
			int a;
			cin >> a;
			cout << query(a) << endl;
		}
	}

	return 0;
}
