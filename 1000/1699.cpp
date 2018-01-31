#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
int dp[100001];
vector<int> power;

int getDp(int here) {
	if (here == 0)
		return 0;

	int& ret = dp[here];
	if (ret != -1) return ret;

	ret = INT_MAX;
	for (auto ele : power) {
		if (ele > here)
			break;
		ret = min(ret, getDp(here - ele) + 1);
	}

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);

	for (int i = 1; i * i <= n; i++)
		power.push_back(i * i);
	
	printf("%d\n", getDp(n));

	return 0;
}