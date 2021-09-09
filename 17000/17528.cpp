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
#define MAX_N 255
#define MOD 31991
#define MOD2 1000000009

int n;
pii arr[MAX_N];
int dp[MAX_N * MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	fill_n(dp, MAX_N * MAX_N, INF);

	dp[0] = arr[0].second;
	dp[arr[0].first] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = MAX_N * MAX_N - 1; j >= 0; --j) {
			if (j >= arr[i].first)
				dp[j] = min({dp[j] + arr[i].second, dp[j - arr[i].first]});
			else
				dp[j] = dp[j] + arr[i].second;
		}
	}

	int ans = INF;
	for (int i = 0; i < MAX_N * MAX_N; ++i) {
		ans = min(ans, max(dp[i], i));
	}
	cout << ans << endl;
	
	return 0;
}