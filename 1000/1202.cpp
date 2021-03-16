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

#define MAX_N 300005

int n, k, c;
pii arr[MAX_N];
multiset<int> bag;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < k; ++i) {
		int t;
		cin >> t;
		bag.insert(t);
	}

	sort(arr, arr + n, [](pii& a, pii& b)->bool {
		return a.second > b.second;
		});

	ll result = 0;
	for (int i = 0; i < n; ++i) {
		auto it = bag.lower_bound(arr[i].first);
		if (it == bag.end())
			continue;
		result += arr[i].second;
		bag.erase(it);
	}
	cout << result << endl;

	return 0;
}