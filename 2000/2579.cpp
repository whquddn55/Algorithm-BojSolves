#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
int dp[300];
vector<int> arr;

int getDp(int here) {
	if (here < 0)
		return 0;
	if (here == 0)
		return dp[here] = arr[here];
	if (here == 1)
		return dp[here] = arr[here] + arr[here - 1];

	int& ret = dp[here];
	if (ret != -1) return ret;
	return ret = max(getDp(here - 3) + arr[here - 1] + arr[here], getDp(here - 2) + arr[here]);
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", getDp(n - 1));

	return 0;
}