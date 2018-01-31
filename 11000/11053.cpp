#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
int dp[1000];
vector<int> arr;

int getDp(int here) {
	if (here == 0)
		return dp[here] = 1;

	int& ret = dp[here];
	if (ret != -1) return ret;

	ret = 1;
	for (int prev = here - 1; prev >= 0; prev--)
		if (arr[here] > arr[prev])
			ret = max(ret, getDp(prev) + 1);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, getDp(i));

	printf("%d\n", result);

	return 0;
}