#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_H 101

int h, w;

int arr[MAX_H][MAX_H];
int arr1[MAX_H][MAX_H];
int arr2[MAX_H][MAX_H];

int dp[MAX_H][MAX_H];

int getDp(int idx1, int idx2) {
	if (idx1 == h)
		return 0;
	if (idx2 == w || idx2 == -1)
		return INF;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = min({ getDp(idx1 + 1, idx2 - 1), getDp(idx1 + 1, idx2), getDp(idx1 + 1, idx2 + 1) }) + arr[idx1][idx2];

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr1[i][j];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr2[i][j];

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			arr[i][j] = (arr1[i][j] - arr2[i][j]) * (arr1[i][j] - arr2[i][j]);

	memset(dp, -1, sizeof(dp));

	int ans = INF;
	for (int i = 0; i < w; i++)
		ans = min(ans, getDp(0, i));

	cout << ans << endl;

	return 0;
}
