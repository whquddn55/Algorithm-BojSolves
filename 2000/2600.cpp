#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int b[3];
bool dp[501][501];

bool getDp(int idx1, int idx2) {
	if ((idx1 < b[0]) && (idx2 < b[0]))
		return dp[idx1][idx2] = false;

	bool& ret = dp[idx1][idx2];
	if (ret != false)
		return ret;

	ret = false;
	for (int i = 0; i < 3; i++) {
		if (idx1 - b[i] >= 0)
			ret = ret || !getDp(idx1 - b[i], idx2);
		if (idx2 - b[i] >= 0)
			ret = ret || !getDp(idx1, idx2 - b[i]);
		if (ret)
			break;
	}
	return ret;
}

int main() {
	for (int i = 0; i < 3; i++)
		scanf("%d", &b[i]);
	sort(b, b + 3);

	for (int i = 0; i < 5; i++) {
		int k1, k2;
		scanf("%d %d", &k1, &k2);
		printf("%c\n", getDp(k1, k2) == true ? 'A' : 'B');

	}

	return 0;
}