#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int dp1[41];
int dp2[41];

int main() {
	scanf("%d %d", &n, &k);

	dp1[0] = 1;
	dp1[1] = 1;
	for (int i = 2; i <= 40; i++)
		dp1[i] = dp1[i - 1] + dp1[i - 2];

	dp2[0] = 0;
	dp2[1] = 1;
	for (int i = 2; i <= 40; i++)
		dp2[i] = dp2[i - 1] + dp1[i - 1];
	
	int result = dp1[k - 1] * dp1[n - k];
	for (int i = 0; i < k - 1; i++)
		result += dp1[n - k] * (dp1[i] * dp1[k - i - 2] + dp2[i] * dp1[k - i - 2] + dp1[i] * dp2[k - i - 2]);
	for (int i = k; i < n; i++)
		result += dp1[k - 1] * (dp1[n - i - 1] * dp1[i - k] + dp2[n - i - 1] * dp1[i - k] + dp1[n - i - 1] * dp2[i - k]);

	printf("%d\n", result);
	return 0;
}