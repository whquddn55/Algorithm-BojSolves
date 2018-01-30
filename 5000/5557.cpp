#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
ll dp[100][21];
vector<int> arr;

ll getDp(int here, int result) {
	if (here == 0)
		return arr[here] == result;

	ll& ret = dp[here][result];
	if (ret != -1) return ret;
	
	ret = 0;
	if (result + arr[here] <= 20)
		ret += getDp(here - 1, result + arr[here]);
	if (result - arr[here] >= 0)
		ret += getDp(here - 1, result - arr[here]);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	dp[0][arr[0]] = 1;
	printf("%lld\n", getDp(n - 2, arr[n - 1]));
	
	return 0;
}