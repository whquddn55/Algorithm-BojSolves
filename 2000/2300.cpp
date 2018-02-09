#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;
int dp[10000];

int main() {
	scanf("%d", &n);
	arr.resize(n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.end());

	int maxY = abs(arr[0].second) * 2;
	for (int i = 0; i < n; i++) {
		maxY = max(maxY, abs(arr[i].second) * 2);
		dp[i] = max(maxY, arr[i].first - arr[0].first);
	}

	for (int i = 1; i < n; i++) {
		maxY = abs(arr[i].second) * 2;
		for (int j = i; j > 0; j--) {
			maxY = max(maxY, abs(arr[j].second) * 2);
			dp[i] = min(dp[i], dp[j - 1] + max(maxY, arr[i].first - arr[j].first));
		}
	}

	printf("%d\n", dp[n - 1]);

	return 0;
}