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
int tree[MAX_N * 4];

void init(int nodeLeft = 0, int nodeRight = n - 1, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight) {
		tree[id] = arr[nodeLeft];
		return;
	}
	init(nodeLeft, mid, id * 2);
	init(mid + 1, nodeRight, id * 2 + 1);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void update(int idx, int value, int nodeLeft = 0, int nodeRight = n - 1, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (idx < nodeLeft || nodeRight < idx)
		return;
	if (nodeLeft == nodeRight) {
		tree[id] += value;
		return;
	}
	update(idx, value, nodeLeft, mid, id * 2);
	update(idx, value, mid + 1, nodeRight, id * 2 + 1);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int k, int nodeLeft = 0, int nodeRight = n - 1, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight)
		return nodeLeft;
	if (tree[id * 2] < k)
		return query(k - tree[id * 2], mid + 1, nodeRight, id * 2 + 1);
	return query(k, nodeLeft, mid, id * 2); 
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	init();
	
	int m;
	cin >> m;
	while(m--) {
		int c;
		cin >> c;
		if (c == 1) {
			int a, b;
			cin >> a >> b;
			--a;
			update(a, b);
		}
		else {
			int a;
			cin >> a;
			cout << query(a) + 1 << endl;
		}
	}

	return 0;
}
