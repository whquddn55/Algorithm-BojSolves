#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
int dp[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;

	cout << dp[n] << endl;
	
	return 0;
}