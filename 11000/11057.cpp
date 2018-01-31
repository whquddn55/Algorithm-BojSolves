#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
int dp[1001][10]; // 자리수가 i이고 끝 자리수가 j인 오르막 수의 개수

int getDp(int here, int num) {
	if (here == 1)
		return 1;

	int& ret = dp[here][num];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= num; i++) 
		ret = (ret + getDp(here - 1, i)) % 10007;

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);

	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result + getDp(n, i)) % 10007;

	printf("%d\n", result);
	
	
	return 0;
}