#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, m;
vector<int> lazy;
vector<int> tree;

int init(int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight)
		return tree[id] = 0;
	else
		return tree[id] = init(id * 2, nodeLeft, mid) + init(id * 2 + 1, mid + 1, nodeRight);
}

void updateLazy(int id, int nodeLeft, int nodeRight) {
	if (lazy[id] % 2) {
		tree[id] = (nodeRight - nodeLeft + 1) - tree[id];

		if (nodeLeft != nodeRight) {
			lazy[id * 2] += 1;
			lazy[id * 2 + 1] += 1;
		}
		lazy[id] = 0;
	}
}

int update(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	updateLazy(id, nodeLeft, nodeRight);
	if (left > nodeRight || right < nodeLeft)
		return tree[id];

	if (left <= nodeLeft && right >= nodeRight) {
		tree[id] = (nodeRight - nodeLeft + 1) - tree[id];
		if (nodeLeft != nodeRight) {
			lazy[id * 2] += 1;
			lazy[id * 2 + 1] += 1;
		}
		return tree[id];
	}

	return tree[id]  = update(left, right, id * 2, nodeLeft, mid) + update(left, right, id * 2 + 1, mid + 1, nodeRight);
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

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;

	lazy.resize(n * 4, 0);
	tree.resize(n * 4, 0);

	while (m--) {

		int o, s, t;
		cin >> o >> s >> t;
		if (o == 0)
			update(s - 1, t - 1);
		else
			cout << query(s - 1, t - 1) << endl;
	}

	return 0;
}
