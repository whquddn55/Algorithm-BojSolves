#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

int n, m;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
		
	for (int i = 0; i < n; i++) 
		if (!arr[i][0]) {
			dp[i][0] = 1;
			ans = 1;
		}
	for (int i = 0; i < m; i++)
		if (!arr[0][i]) {
			dp[0][i] = 1;
			ans = 1;
		}

	int dy[] = { -1, 0, -1 };
	int dx[] = { 0, -1, -1 };
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			if (arr[i][j])
				dp[i][j] = 0;
			else {
				int minValue = INF;
				for (int k = 0; k < 3; k++)
					minValue = min(minValue, dp[i + dy[k]][j + dx[k]]);

				dp[i][j] = minValue + 1;
				ans = max(ans, dp[i][j]);
			}
		}

	cout << ans << endl;
	
	return 0;
}