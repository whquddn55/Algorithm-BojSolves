#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 301

int n, m;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	dp[0][0] = arr[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
		}

	cout << dp[n - 1][m - 1] << endl;
	
	return 0;
}