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

int n;
pii arr[MAX_N];
int tree[MAX_N * 4];
ll tree2[MAX_N * 4];

int update(int index, int value, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (index < nodeLeft || index > nodeRight)
		return tree[id];
	if (nodeLeft == nodeRight)
		return tree[id] += value;
	return tree[id] = update(index, value, id * 2, nodeLeft, mid) + update(index, value, id * 2 + 1, mid + 1, nodeRight);
}

int query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (right < nodeLeft || left > nodeRight)
		return 0;
	if (left <= nodeLeft && right >= nodeRight)
		return tree[id];
	return query(left, right, id * 2, nodeLeft, mid) + query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

ll update2(int index, int value, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (index < nodeLeft || index > nodeRight)
		return tree2[id];
	if (nodeLeft == nodeRight)
		return tree2[id] += value;
	return tree2[id] = update2(index, value, id * 2, nodeLeft, mid) + update2(index, value, id * 2 + 1, mid + 1, nodeRight);
}

ll query2(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (right < nodeLeft || left > nodeRight)
		return 0;
	if (left <= nodeLeft && right >= nodeRight)
		return tree2[id];
	return query2(left, right, id * 2, nodeLeft, mid) + query2(left, right, id * 2 + 1, mid + 1, nodeRight);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].second;
	sort(arr, arr + n, [](pii& a, pii& b)->bool{
		return a.first==b.first?a.second>b.second:a.first<b.first;
	});

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		update(arr[i].second, 1);
		int qValue = query(0, arr[i].second - 1);
		update2(arr[i].second, qValue);
		ans += query2(0, arr[i].second - 1);
	}
	cout << ans << endl;
}