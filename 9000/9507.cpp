#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define	MAX_SIZE 68

int n;
ll dp[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX_SIZE; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << dp[n] << endl;
	}


	return 0;
}
