#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
int dp[1001][3][2];

int getDp(int idx1, int idx2, int idx3) {
	if ((idx1 == idx2 + idx3) || (idx1 == 1 && idx2 == 0 && idx3 == 0)) 
		return 1;

	if (idx1 < idx2 + idx3) 
		return 0;
	

	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	ret = 0;
	if (idx2 == 0) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j <= idx3; j++)
				ret += getDp(idx1 - 1, i, j);
	}
	else 
		ret += getDp(idx1 - 1, idx2 - 1, idx3);
	return ret % 1000000;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", (getDp(n, 0, 0) + getDp(n, 1, 0) + getDp(n, 2, 0) + getDp(n, 0, 1) + getDp(n, 1, 1) + getDp(n, 2, 1)) % 1000000);

	return 0;
}