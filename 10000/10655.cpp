#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n;
pii arr[MAX_N];
int dp[MAX_N][2];

int getDp(int idx1, int idx2) {
	if (idx1 == n - 1)
		return 0;
	if (idx1 == n - 2)
		return dp[idx1][idx2] = abs(arr[idx1].first - arr[idx1 + 1].first) + abs(arr[idx1].second - arr[idx1 + 1].second);

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	if (idx2)
		return ret = getDp(idx1 + 1, idx2) + abs(arr[idx1].first - arr[idx1 + 1].first) + abs(arr[idx1].second - arr[idx1 + 1].second);
	else
		return ret = min(getDp(idx1 + 1, idx2) + abs(arr[idx1].first - arr[idx1 + 1].first) + abs(arr[idx1].second - arr[idx1 + 1].second),
			getDp(idx1 + 2, 1) + abs(arr[idx1].first - arr[idx1 + 2].first) + abs(arr[idx1].second - arr[idx1 + 2].second));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i].first >> arr[i].second;
	
	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 0) << endl;

	return 0;
}