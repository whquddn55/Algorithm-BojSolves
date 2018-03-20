#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
ll dp[10001];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;

	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;

	for (int i = 6; i <= n; i += 2) 
		for (int j = 0; j <= i - 2; j += 2) 
			dp[i] = (dp[i] + (dp[i - j - 2] * dp[j]) % 987654321) % 987654321;
		
	

	cout << dp[n] << endl;

	return 0;
}
