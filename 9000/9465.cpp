#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
int dp[100001][2]; // 자리수가 i이고 끝 자리수가 j인 이친수의 개수
vector<int> arr[2];

int getDp(int here, int num) {
	if (here == 0)
		return dp[here][num] = arr[num][here];
	

	int& ret = dp[here][num];
	if (ret != -1) return ret;

	ret = max(getDp(here - 1, !num) + arr[num][here], getDp(here - 1, num));

	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		arr[0].resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[0][i]);
		arr[1].resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[1][i]);

		printf("%d\n", max(getDp(n - 1, 0), getDp(n - 1, 1)));
	}

	return 0;
}