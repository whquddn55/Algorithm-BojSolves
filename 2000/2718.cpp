#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 26

int dp[MAX_SIZE][6];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	dp[1][0] = 1;
	for (int i = 2; i < 25; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][3];
		dp[i][2] = dp[i - 1][4];
		dp[i][3] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][4] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][5] = dp[i - 1][0];
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << dp[n + 1][0] << endl;
	}

	return 0;
}