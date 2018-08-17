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

#define INF (LLONG_MAX / 2)

#define MAX_N 100000
#define MAX_M 300

int n;
ll dp[3];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		dp[2] = dp[1] + dp[0];
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	cout << dp[min(n, 2)] << endl;

	return 0;
}