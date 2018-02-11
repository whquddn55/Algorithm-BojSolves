#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int dp[3][50000];
vector<int> arr;
vector<int> sum;

int getDp(int here, int cnt) {
	if (here >= n || cnt ==  3)
		return 0;

	int& ret = dp[cnt][here];
	if (ret != -1)
		return ret;

	ret = max(sum[here] + getDp(here + k, cnt + 1), getDp(here + 1, cnt ));

	return ret;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);

	sum.resize(n, 0);
	for (int i = 0; i <= n - k; i++)
		for (int j = i; j < i + k; j++)
			sum[i] += arr[j];

	memset(dp, -1, sizeof(dp));

	printf("%d\n", getDp(0, 0));

#ifdef DEBUG
	for (int i = 0; i < n; i++)
		cout << sum[i] << endl;
#endif

	return 0;
}