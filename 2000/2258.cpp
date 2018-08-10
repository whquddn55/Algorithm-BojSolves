#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100000

int n, m;
pair<ll, ll> arr[MAX_N];
ll psum;

ll ans = LLONG_MAX;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + n, [](pair<ll, ll>& a, pair<ll, ll>& b) {
		return a.second == b.second ? a.first > b.first : a.second < b.second;
	});

	ll tsum = arr[0].first;
	ll ttsum = arr[0].second;
	psum = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1].second == arr[i].second) {
			tsum += arr[i].first;
			ttsum += arr[i].second;
			if (psum + tsum >= m)
				ans = min(ans, ttsum);
			continue;
		}
		psum += tsum + arr[i].first;
		tsum = 0;
		ttsum = arr[i].second;
		if (psum >= m) 
			ans = min(ans, ttsum);
	}

	cout << (ans == LLONG_MAX ? -1 : ans) << endl;

	return 0;
}
