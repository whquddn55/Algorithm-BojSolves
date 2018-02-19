#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int d, k;
int dp1[31];
int dp2[31];

int main() {
	scanf("%d %d", &d, &k);

	dp1[1] = 1;
	dp2[1] = 0;
	dp1[2] = 0;
	dp2[2] = 1;

	for (int i = 3; i <= 30; i++) {
		dp1[i] = dp1[i - 1] + dp1[i - 2];
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}

	int ret1 = 0, ret2 = 0;
	while (k >= dp1[d]) {
		k -= dp1[d];
		ret1++;
		if (k % dp2[d] == 0) {
			ret2 = k / dp2[d];
			break;
		}
	}
	printf("%d\n%d\n", ret1, ret2);

	return 0;
}