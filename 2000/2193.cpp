#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
ll dp[91][2]; // 자리수가 i이고 끝 자리수가 j인 이친수의 개수

ll getDp(int here, int num) {
	if (here == 1) 
		return dp[here][num] = num;
	

	ll& ret = dp[here][num];
	if (ret != -1) return ret;

	ret = getDp(here - 1, 0);
	if (num == 0)
		ret += getDp(here - 1, 1);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);

	printf("%lld\n", getDp(n, 0) + getDp(n, 1));

	return 0;
}