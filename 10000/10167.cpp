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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 3005
#define MOD 1000003

struct Data {
	ll lmax = -INF, rmax = -INF, mmax = -INF, sum = 0;
};

int n;
pair<pii, int> arr[MAX_N];
map<int, int> mapper;
Data tree[MAX_N * 4];

void update(int index, ll value, int nl = 0, int nr = MAX_N - 1, int id = 1) {
	if (index < nl || nr < index)
		return;
	if (nl == nr) {
		tree[id].sum += value;
		tree[id].lmax = tree[id].sum;
		tree[id].rmax = tree[id].sum;
		tree[id].mmax = tree[id].sum;
		return;
	}
	int mid = (nl + nr) / 2;
	update(index, value, nl, mid, id * 2);
	update(index, value, mid + 1, nr, id * 2 + 1);

	tree[id].lmax = max(tree[id * 2].lmax, tree[id * 2 + 1].lmax + tree[id * 2].sum);
	tree[id].rmax = max(tree[id * 2 + 1].rmax, tree[id * 2].rmax + tree[id * 2 + 1].sum);
	tree[id].mmax = max({tree[id * 2].mmax, tree[id * 2 + 1].mmax, tree[id * 2].rmax + tree[id * 2 + 1].lmax});
	tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		mapper.emplace(arr[i].first.second, 1);
	}
	int cnt = 0;
	for (auto p : mapper)
		mapper[p.first] = cnt++;

	for (int i = 0; i < n; ++i)
		arr[i].first.second = mapper[arr[i].first.second];
	sort(arr, arr + n);

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i && arr[i].first.first == arr[i - 1].first.first)
			continue;
		for (int j = 0; j < MAX_N * 4; ++j)
			tree[j] = {0, 0, 0, 0};
		for (int j = i; j < n; ++j) {
			update(arr[j].first.second, arr[j].second);
			if (j == n - 1 || arr[j].first.first != arr[j + 1].first.first)
				ans = max(ans, tree[1].mmax);
		}
	}
	cout << ans << endl;
	
	return 0;
}
