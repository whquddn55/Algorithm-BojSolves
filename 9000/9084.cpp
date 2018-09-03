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

#define MAX_N 20
#define MAX_M 10001

int n, m;
int arr[MAX_N];
int dp[MAX_M];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> m;

		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = arr[i]; j <= m; j++) 
				dp[j] += dp[j - arr[i]];
		}
		cout << dp[m] << endl;
	}
	return 0;
}