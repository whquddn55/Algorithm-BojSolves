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
#define MAX_N 16
#define MOD 1000003

int n;
int arr[MAX_N];
ll dp[1 << MAX_N][10];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	ll ans = 0;
	ll sum = 0;
	for (int ex = 0; ex < n; ++ex) {
		memset(dp, 0, sizeof(dp));
		int exBit = (1 << ex);
		dp[0][0] = 1;
		for (int i = 0; i < (1 << n); ++i) {
			if (i & exBit)
				continue;
			for (int j = 0; j < 10; ++j) {
				for (int k = 0; k < n; ++k) {
					if (k == ex)
						continue;

					int nextBit = (1 << k);
					if (i & nextBit)
						continue;
					dp[i | nextBit][(j * 10 + arr[k]) % arr[ex]] += dp[i][j];
				}
			}
		}

		ans += dp[((1 << n) - 1) ^ exBit][0];
		for (int i = 0; i < 10; ++i)
			sum += dp[((1 << n) - 1) ^ exBit][i];
	}
	cout << fixed;
	cout.precision(12);
	cout << (double)ans / sum << endl;
	
	
	return 0;
}
