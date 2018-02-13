#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
int dp[2001][2001];

bool getDp(int idx1, int idx2) {
	if (idx1 == idx2)
		return true;
	if (idx1 == idx2 - 1)
		return arr[idx1] == arr[idx2];

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = (arr[idx1] == arr[idx2]) && getDp(idx1 + 1, idx2 - 1);
	return ret;
}

int main() {
	scanf("%d", &n);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	
	int m;
	scanf("%d", &m);
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", getDp(s, e));
	}
	
	return 0;
}