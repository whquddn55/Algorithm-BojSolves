#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> dp; // i에서 시작하는 가장의 최대 증가 부분 순열의 합

int get(int here) {
	if (here == n - 1)
		return arr[here];

	int& ret = dp[here];
	if (ret != -1) return ret;
	ret = arr[here];
	for (int next = here + 1; next < n; next++)
		if (arr[here] < arr[next])
			ret = max(ret, get(next) + arr[here]);

	return ret;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	dp.resize(n, -1);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, get(i));
	printf("%d\n", result);

	return 0;
}