#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;

	cout << dp[n] << endl;

	return 0;
}
