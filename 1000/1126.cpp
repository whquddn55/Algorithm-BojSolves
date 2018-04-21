#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 51

int n;
int arr[MAX_N];
int dp[MAX_N][500001];

int getDp(int idx1, int idx2) {
	if (idx1 == n)
		return idx2 ? -2 : 0;
	if (idx2 < 0)
		return -2;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = -2;

	int r1 = getDp(idx1 + 1, idx2);
	int r2 = getDp(idx1 + 1, idx2 + arr[idx1]);
	int r3 = getDp(idx1 + 1, idx2 - arr[idx1]);
	int r4 = getDp(idx1 + 1, arr[idx1] - idx2);

	if (r1 != -2)
		ret = max(ret, r1);
	if (r2 != -2)
		ret = max(ret, r2 + arr[idx1]);
	if (r3 != -2)
		ret = max(ret, r3 + arr[idx1]);
	if (r4 != -2)
		ret = max(ret, r4 + arr[idx1]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	int ret = getDp(0, 0);
	cout << (ret <= 0 ? -1 : ret / 2) << endl;

	return 0;
}

