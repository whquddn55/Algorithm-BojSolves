#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define	MAX_SIZE 1001

int n, m;
char arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
		}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (arr[i][j]) {
				dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	

	cout << ans * ans << endl;


	return 0;
}
