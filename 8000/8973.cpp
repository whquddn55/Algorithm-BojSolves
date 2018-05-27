#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 2001

int n;
int arr1[MAX_N];
int arr2[MAX_N];
int dp[MAX_N][MAX_N];

int maxValue = -INF;
pii ans;

int getDp(int idx1, int idx2) {
	if (idx1 + idx2 >= n)
		return 0;
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	
	ret = getDp(idx1 + 1, idx2 + 1);
	if (idx1 == n - 1 - idx2)
		ret += arr1[idx1] * arr2[idx1];
	else
		ret += arr1[idx1] * arr2[n - 1 - idx2] + arr1[n - 1 - idx2] * arr2[idx1];

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	memset(dp, -1, sizeof(dp));
	for (int b = 0; b < n; b++)
		for (int e = 0; e < n - b; e++) {
			int value = getDp(b, e);
			if (maxValue < value) {
				maxValue = value;
				ans = { b, e };
			}
		}

	cout << ans.first << ' ' << ans.second << endl;
	cout << maxValue << endl;

	return 0;
}