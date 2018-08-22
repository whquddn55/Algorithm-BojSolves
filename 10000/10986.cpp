#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_M 1000

int n, m;
ll sum = 0;
int cnt[MAX_M];

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum += t;
		cnt[sum % m]++;

		if (sum % m == 0)
			ans += cnt[0];
		else
			ans += cnt[sum % m] - 1;
	}
	cout << ans << endl;
	
	return 0;
}