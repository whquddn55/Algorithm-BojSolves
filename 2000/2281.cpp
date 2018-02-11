#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
int dp[1000][1001]; // i번째 이름을 놓을 차례이고, j만큼의 여백이 있을 때 (n - 1)번째 이름을 놓을 때 까지 여백의 제곱의 합의 최소

int getDp(int here, int margin) {
	if (margin < 0)
		return INF;
	if (here == n)
		return 0;

	int& ret = dp[here][margin];
	if (ret != -1)
		return ret;

	ret = min(getDp(here + 1, margin - arr[here] - 1), getDp(here + 1, m - arr[here]) + margin * margin);

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));

	printf("%d\n", getDp(1, m - arr[0]));

	return 0;
}