#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX / 2
#define MAXSIZE 100001

int n;
vector<vector<int> > arr;
int dp[MAXSIZE][3];

int get(int r, int c ) {
	if (r < 0 || c < 0 || c >= 3)
		return INF;
	if (r == 0 && c == 1)
		return arr[r][c];

	int& ret = dp[r][c];
	if (ret != -1) return ret;
	return ret = arr[r][c] + min({get(r, c - 1), get(r - 1, c - 1), get(r - 1, c), get(r - 1, c + 1)});
}

int main() {
	int cnt = 0;
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		cnt++;

		arr.clear();
		arr.resize(n);
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			arr[i].resize(3);
			for (int j = 0; j < 3; j++)
				scanf("%d", &arr[i][j]);
		}

		get(n - 1, 1);
		printf("%d. %d\n", cnt ,dp[n - 1][1]);
	}


	return 0;
}