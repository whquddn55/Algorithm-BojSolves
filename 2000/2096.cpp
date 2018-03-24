#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
int dp[2][3];
int dp2[2][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int arr[3];
		for (int j = 0; j < 3; j++)
			cin >> arr[j];
	
		if (i == 0) {
			dp[0][0] = arr[0];
			dp[0][1] = arr[1];
			dp[0][2] = arr[2];

			dp2[0][0] = arr[0];
			dp2[0][1] = arr[1];
			dp2[0][2] = arr[2];
		}
		else {
			dp[1][0] = max(dp[0][0], dp[0][1]) + arr[0];
			dp[1][1] = max({ dp[0][0], dp[0][1], dp[0][2] }) + arr[1];
			dp[1][2] = max(dp[0][1], dp[0][2]) + arr[2];

			dp2[1][0] = min(dp2[0][0], dp2[0][1]) + arr[0];
			dp2[1][1] = min({ dp2[0][0], dp2[0][1], dp2[0][2] }) + arr[1];
			dp2[1][2] = min(dp2[0][1], dp2[0][2]) + arr[2];

			dp[0][0] = dp[1][0];
			dp[0][1] = dp[1][1];
			dp[0][2] = dp[1][2];

			dp2[0][0] = dp2[1][0];
			dp2[0][1] = dp2[1][1];
			dp2[0][2] = dp2[1][2];
		}
	}

	cout << max({ dp[0][0], dp[0][1], dp[0][2] }) << ' ' << min({ dp2[0][0], dp2[0][1], dp2[0][2] }) << endl;
	
	return 0;
}