#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define	MAX_SIZE 1001

int n, k;
int dp[MAX_SIZE][MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;

	cout << dp[n][k] << endl;

	return 0;
}
