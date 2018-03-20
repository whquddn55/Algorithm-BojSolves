#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
int dp[1001][3];
vector<vector<int> > arr;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;

	arr.resize(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
		dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][2] + arr[i][1]);
		dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
	}

	cout << min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << endl;

	return 0;
}
