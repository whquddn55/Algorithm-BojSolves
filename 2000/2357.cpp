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

#define MAX_N 100000
#define MOD 1000000007

int n, m;
int arr[MAX_N];
pii tree[MAX_N * 4];

pii init(int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (nodeLeft == nodeRight) 
		return tree[node] = pii(arr[nodeLeft], arr[nodeLeft]);
	
	int mid = (nodeLeft + nodeRight) / 2;
	pii v1 = init(node * 2, nodeLeft, mid);
	pii v2 = init(node * 2 + 1, mid + 1, nodeRight);
	return tree[node] = pii(min(v1.first, v2.first), max(v1.second, v2.second));
}

pii query(int l, int r, int node = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (l <= nodeLeft && r >= nodeRight)
		return tree[node];
	if (nodeRight < l || nodeLeft > r)
		return pii(INF, 0);


	int mid = (nodeLeft + nodeRight) / 2;
	pii v1 = query(l, r, node * 2, nodeLeft, mid);
	pii v2 = query(l, r, node * 2 + 1, mid + 1, nodeRight);
	return pii(min(v1.first, v2.first), max(v1.second, v2.second));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	init();
	while (m--) {
		int f, t;
		cin >> f >> t;
		f--; t--;
		cout << query(f, t) << endl;
	}

	return 0;
}