#include <iostream>
#include <vector>
using namespace std;

long long dp[81];

int main() {
	dp[1] = 4;
	dp[2] = 6;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] << endl;

	return 0;
}
