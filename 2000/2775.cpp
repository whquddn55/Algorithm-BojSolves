#include <bits/stdc++.h>
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
#define MAX_N 15

int n, k;
int dp[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 1; i < MAX_N; i++)
		dp[0][i] = i;
	for (int i = 1; i < MAX_N; i++)
		for (int j = 1; j < MAX_N; j++)
			for (int k = 1; k <= j; k++)
				dp[i][j] += dp[i - 1][k];


	int tc;
	cin >> tc;
	while (tc--) {
		cin >> k >> n;
		cout << dp[k][n] << endl;
	}

	return 0;
}
