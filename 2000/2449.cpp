#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
int dp[201][201]; // [i, j]구간이 모두 k색이 되기 위해 바꾸어야하는 전구의 [최소] 개수

int get(int l, int r) {
	if (l == r)
		return 0;
	int& ret = dp[l][r];
	if (ret != -1) return ret;

	ret = INT_MAX;
	for (int i = l; i < r; i++) 
		ret = min(ret, get(l, i) + get(i + 1, r) + (arr[l] != arr[i + 1]));
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	memset(dp, -1, sizeof(dp));
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	
	printf("%d\n", get(0, n - 1));
	return 0;
}