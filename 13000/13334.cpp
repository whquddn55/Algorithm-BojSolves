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
#define MOD 1000000007

#define MAX_N 100005

int n, l;
pii arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i].first > arr[i].second)
			swap(arr[i].first, arr[i].second);
	}
	sort(arr, arr + n, [](pii& a, pii& b) -> bool {
		return a.second < b.second;
	});
	cin >> l;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i].second - arr[i].first > l)
			continue;
		pq.emplace(arr[i].first, arr[i].second);
		while (pq.size() && pq.top().first < arr[i].second - l)
			pq.pop();
		ret = max(ret, (int)pq.size());
	}
	cout << ret << endl;

	return 0;
}