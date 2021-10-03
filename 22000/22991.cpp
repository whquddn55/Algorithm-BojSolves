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
#define MAX_N 200005
#define MOD 1000000007

int n, m;
pii arr[MAX_N];
pii brr[MAX_N];
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < m; ++i)
		cin >> brr[i];

	sort(arr, arr + n, [](pii&a, pii&b) -> bool {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	});

	sort(brr, brr + m, [](pii&a, pii&b) -> bool {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	});

	int bIndex = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while(bIndex < m && arr[i].first <= brr[bIndex].first) {
			s.emplace(brr[bIndex].second);
			++bIndex;
		}

		if (s.size()) {
			auto it = s.upper_bound(arr[i].second);
			if (it == s.begin())
				continue;
			--it;
			++ans;
			s.erase(it);
		}
	}
	cout << ans << endl;

	return 0;
}