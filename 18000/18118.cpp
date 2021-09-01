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
#define MAX_N 100005
#define MOD 1000003

int n, m;
ll dp[10][MAX_N]; 

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--) {
		memset(dp, 0, sizeof(dp));

		cin >> n >> m;

		for (int k = 0; k <= 9; ++k) 
			dp[1][k % m] = max(dp[1][k % m], (ll)k);
		dp[1][11 % m] = max(dp[1][11 % m], (ll)11);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (dp[i][j]) {
					for (int k = 0; k <= 9; ++k) 
						dp[i + 1][(j * 10 + k) % m] = max(dp[i + 1][(j * 10 + k) % m], dp[i][j] * 10 + k);
					dp[i + 1][(j * 100 + 11) % m] = max(dp[i + 1][(j * 100 + 11) % m], dp[i][j] * 100 + 11);
				}
			}
		}
		
			cout << dp[n][0] << endl;
	}
	
	return 0;
}
