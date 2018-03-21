#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
vector<int> tree;

int update(int index, int diff, int id = 1, int nodeLeft = 0, int nodeRight = 1000001 - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (index < nodeLeft || index > nodeRight)
		return tree[id];

	if (nodeLeft == nodeRight)
		return (tree[id] += diff);
	else 
		return tree[id] = update(index, diff, id * 2, nodeLeft, mid) + update(index, diff, id * 2 + 1, mid + 1, nodeRight);
}

int query(int k, int id = 1, int nodeLeft = 0, int nodeRight = 1000001 - 1) {
	int mid = (nodeLeft + nodeRight) / 2;

	if (nodeLeft == nodeRight)
		return nodeLeft;

	if (tree[id * 2] >= k)
		return query(k, id * 2, nodeLeft, mid);
	return query(k - tree[id * 2], id * 2 + 1, mid + 1, nodeRight);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	tree.resize(1000000 * 4);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			int toGet = query(b);
			update(toGet, -1);
			cout << toGet << endl;
		}
		else {
			int c;
			cin >> c;

			update(b, c);
		}
	}
	
}
