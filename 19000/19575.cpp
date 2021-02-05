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
#define MOD  1000000007LL

ll dp[MAX_N] = { 0, };

ll power(ll value, ll degree) {
	if (dp[degree])
		return dp[degree];
	return dp[degree] = (power(value, degree / 2) * power(value, (degree + 1) / 2)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	n++;

	dp[0] = 1;
	dp[1] = x;

	ll result = 0;
	while (n--) {
		int a, i;
		cin >> a >> i;
		if (a)
			result = (result + (a * power(x, i)) % MOD) % MOD;
	}
	cout << result << endl;
	
	return 0;
}