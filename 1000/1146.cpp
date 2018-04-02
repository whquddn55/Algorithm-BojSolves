#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101

int n;
int dp[MAX_SIZE][MAX_SIZE][2]; // k가 1 :이전보다 큰 놈이다.-> 작는 놈 고를 차례다 0 : 이전보다 작은 놈이다

int getDp(int idx1, int idx2, bool idx3) {
	// base case
	if (idx1 < 0 || idx2 < 0)
		return 0;
	if (idx3 && idx1 == 0)
		return 0;
	if (!idx3 && idx2 == 0)
		return 0;

	int &ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;
	
	ret = 0;
	if (idx3) {
		for (int i = 0; i < idx1; i++)
			ret = (ret + getDp(idx1 - i - 1, idx2 + i, !idx3)) % 1000000;
	}
	else {
		for (int i = 0; i < idx2; i++)
			ret = (ret + getDp(idx1 + i, idx2 - i - 1, !idx3)) % 1000000;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	fill(&dp[0][0][0], &dp[0][0][0] + MAX_SIZE * MAX_SIZE * 2, -1);

	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	dp[0][1][0] = 1;
	dp[1][0][1] = 1;
	
	int ans = 0;
	for (int i = 0; i < n; i++) 
		ans = (ans + (getDp(i, n - i - 1, 0) + getDp(i, n - i - 1, 1)) % 1000000) % 1000000;
	
	cout << ans << endl;

	return 0;
}
