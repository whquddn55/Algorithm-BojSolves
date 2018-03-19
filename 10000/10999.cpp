#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, m, k;
vector<ll> arr;
vector<ll> lazy;
vector<ll> tree;

ll init(int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight)
		return tree[id] = arr[nodeLeft];
	else
		return tree[id] = init(id * 2, nodeLeft, mid) + init(id * 2 + 1, mid + 1, nodeRight);
}

void updateLazy(int id, int nodeLeft, int nodeRight) {
	if (lazy[id] != 0) {
		tree[id] += (nodeRight - nodeLeft + 1) * lazy[id];

		if (nodeLeft != nodeRight) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
}

void update(int left, int right, ll value, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (left > nodeRight || right < nodeLeft)
		return;

	if (left <= nodeLeft && right >= nodeRight) {
		tree[id] += (nodeRight - nodeLeft + 1) * value;
		if (nodeLeft != nodeRight) {
			lazy[id * 2] += value;
			lazy[id * 2 + 1] += value;
		}
		return;
	}
	update(left, right, value, id * 2, nodeLeft, mid);
	update(left, right, value, id * 2 + 1, mid + 1, nodeRight);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (right < nodeLeft || left > nodeRight)
		return 0;
	if (left <= nodeLeft && right >= nodeRight)
		return tree[id];
	
	return query(left, right, id * 2, nodeLeft, mid) + query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	lazy.resize(n * 4, 0);
	tree.resize(n * 4);
	init();

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			ll d;
			cin >> d;
			update(b - 1, c - 1, d);
		}
		else {
			cout << query(b - 1, c - 1) << endl;
		}
	}
	
	return 0;
}
