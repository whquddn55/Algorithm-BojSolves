#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101

int n;
ll dp[MAX_SIZE];

ll getDp(int idx1) {
	if (idx1 <= 3)
		return dp[idx1] = idx1;

	ll& ret = dp[idx1];
	if (ret != -1)
		return ret;

	for (int i = 0; i <= idx1 - 3; i++)
		ret = max(ret, getDp(i) * (2 + (idx1 - 3) - i));

	return ret = max(ret, getDp(idx1 - 1) + 1);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	
	memset(dp, -1, sizeof(dp));
	cout << getDp(n) << endl;

	return 0;
}
