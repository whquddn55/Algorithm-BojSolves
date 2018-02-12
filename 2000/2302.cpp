#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
int dp[41];

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	if (m == 0) {
		printf("%d\n", dp[n]);
	}
	else {
		int result = dp[arr[0] - 1];
		for (int i = 1; i < m; i++) 
			result *= dp[arr[i] - arr[i - 1] - 1];
		result *= dp[n - arr[m - 1]];

		printf("%d\n", result);
	}

	return 0;
}