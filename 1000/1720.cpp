#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 31

int n;
int dp[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	if (n <= 2) {
		cout << dp[n] << endl;
		return 0;
	}
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	if (n % 2)
		cout << dp[n / 2] + (dp[n] - dp[n / 2]) / 2 << endl;
	else
		cout << dp[n / 2] + dp[n / 2 - 1] * 2 + (dp[n] - dp[n / 2] - dp[n / 2 - 1] * 2) / 2 << endl;

	return 0;
}
