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

int n, m;
int arr[MAX_N];
int tree[MAX_N * 4];
int lazy[MAX_N * 4];

int init(int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight)
		return tree[id] = arr[nodeLeft];

	return tree[id] = init(id * 2, nodeLeft, mid) ^ init(id * 2 + 1, mid + 1, nodeRight);
}

void updateLazy(int id, int nodeLeft, int nodeRight) {
	if (lazy[id]) {
		tree[id] ^= lazy[id];
		if (nodeLeft != nodeRight) {
			lazy[id * 2] ^= lazy[id];
			lazy[id * 2 + 1] ^= lazy[id];
		}
		lazy[id] = 0;
	}
}

void update(int left, int right, int value, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (right < nodeLeft || nodeRight < left) 
		return;
	if (left <= nodeLeft && nodeRight <= right) {
		lazy[id] ^= value;
		updateLazy(id, nodeLeft, nodeRight);
		return;
	}
	update(left, right, value, id * 2, nodeLeft, mid);
	update(left, right, value, id * 2 + 1, mid + 1, nodeRight);
	tree[id] = tree[id * 2] ^ tree[id * 2 + 1];
}

int query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (right < nodeLeft || nodeRight < left)
		return 0;
	if (left <= nodeLeft && nodeRight <= right)
		return tree[id];
	return query(left, right, id * 2, nodeLeft, mid) ^ query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	init();

	cin >> m;
	while(m--) {
		int o;
		cin >> o;
		if (o == 1){
			int f, t, c;
			cin >> f >> t >> c;
			update(f, t, c);
		}
		else {
			int f;
			cin >> f;
			cout << query(f, f) << endl;
		}
	}

	return 0;
}
