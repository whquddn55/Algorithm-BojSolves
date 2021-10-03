#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MX = 202020;
const ll INF = 9e15;
const ll MOD = 1'000'000'007;
ll n, m, dp[333][8777][2], chk;
string s;
int main() {
	cin.tie(0); 
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'z') chk = 1;
	}
	dp[0][0][chk] = 1;
	for (int i = 0; i < s.size(); i++) {
		ll dist = 'z' - s[i];
		for (int j = 0; j <= i * 26; j++) {
			for (int k = 0; k <= dist; k++) {
				for(int w = 0; w < 2; w++) {
					ll f = w;
					if (k == dist) f = 1;
					dp[i + 1][j + k][f] += dp[i][j][w];
					dp[i + 1][j + k][f] %= MOD;
				}
			}
		}
	}
	ll ret = 0;
	if (m <= n * 26) {
		ret += (dp[n][m][0] + dp[n][m][1]) % MOD;
	}
	for (int i = 0; i <= min(m-1,n*26); i++) {
		ret += dp[n][i][1];
		ret %= MOD;
	}
	cout << ret;
}
