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
pair<pll, int> arr[MAX_N];
vector<ll> temp;
int tree[MAX_N * 8];

void update(int index, int value, int id = 1, int nodeLeft = 0, int nodeRight = temp.size() - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (index < nodeLeft || index > nodeRight) 
		return;
	if (nodeLeft == nodeRight) {
		tree[id] += value;
		return;
	}
	update(index, value, id * 2, nodeLeft, mid);
	update(index, value, id * 2 + 1, mid + 1, nodeRight);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int l, int r, int id = 1, int nodeLeft = 0, int nodeRight = temp.size() - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if  (r < nodeLeft || l > nodeRight)
		return 0;
	if (l <= nodeLeft && r >= nodeRight)
		return tree[id];
	return query(l, r, id * 2, nodeLeft, mid) + query(l, r, id * 2 + 1, mid + 1, nodeRight);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		temp.emplace_back(arr[i].first.first - arr[i].first.second);
		temp.emplace_back(arr[i].first.first + arr[i].first.second);
		arr[i].second = i;
	}

	sort(arr, arr + n, [](pair<pll, int>& a, pair<pll, int>& b) -> bool {
		return a.first.second > b.first.second;
	});

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int from = lower_bound(temp.begin(), temp.end(), arr[i].first.first - arr[i].first.second) - temp.begin();
		int to = lower_bound(temp.begin(), temp.end(), arr[i].first.first + arr[i].first.second) - temp.begin();
		if (query(from + 1, to) == 0 && query(0, from) == 0) {
			ans.push_back(arr[i].second + 1);
			update(from, -1);
			update(to + 1, 1);
		}
	}

	cout << ans.size() << endl;
	for (auto e : ans)
		cout << e << ' ';

	return 0;
}