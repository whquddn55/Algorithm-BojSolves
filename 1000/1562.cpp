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

#define MAX_N 105

int n;
int dp[MAX_N][10][1 << 10];


int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 1; i < 10; ++i)
		dp[0][i][1 << i] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 0) {
				for (int k = 0; k < (1 << 10); ++k)
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][1][k]) % 1000000000;
			}
			else if (j == 9) {
				for (int k = 0; k < (1 << 10); ++k)
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][8][k]) % 1000000000;
			}
			else {
				for (int k = 0; k < (1 << 10); ++k) 
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % 1000000000) % 1000000000;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 10; ++i)
		ret = (ret + dp[n - 1][i][1023]) % 1000000000;
	cout << ret << endl;

	
	return 0;
}