#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
vector<int> ans;
vector<int> tree;

int update(int pos, int value, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (pos < nodeLeft || pos > nodeRight)
		return tree[id];
	if (nodeLeft == nodeRight)
		return tree[id] = value;

	return tree[id] = update(pos, value, id * 2, nodeLeft, mid) +
		update(pos, value, id * 2 + 1, mid + 1, nodeRight);
}

int query(int value, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight)
		return nodeLeft;
	if (tree[id * 2] >= value)
		return query(value, id * 2, nodeLeft, mid);
	return query(value - tree[id * 2], id * 2 + 1, mid + 1, nodeRight);
}

int main() {
	cin >> n;
	ans.resize(n, 0);
	tree.resize(n * 4);
	
	for (int i = 0; i < n; i++)
		update(i, 1);

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		int index = query(t + 1);
		ans[index] = i;
		update(index, 0);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
}