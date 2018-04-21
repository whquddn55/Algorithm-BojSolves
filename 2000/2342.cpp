#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 100001

int n = 0;
int arr[MAX_SIZE];

int table[5][5] = { 
	{1, 2, 2, 2, 2}, 
	{2, 1, 3, 4, 3}, 
	{2, 3, 1, 3, 4}, 
	{2, 4, 3, 1, 3}, 
	{2, 3, 4, 3, 1} 
};
int dp[MAX_SIZE][5][5];

int getDp(int idx1, int idx2, int idx3) {
	if (idx1 == n)
		return 0;

	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	return ret = min(getDp(idx1 + 1, arr[idx1], idx3) + table[idx2][arr[idx1]], getDp(idx1 + 1, idx2, arr[idx1]) + table[idx3][arr[idx1]]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	for (n = 0; n < MAX_SIZE; n++) {
		cin >> arr[n];
		if (arr[n] == 0)
			break;
	}

		memset(dp, -1, sizeof(dp));
		cout << getDp(0, 0, 0) << endl;
	
	return 0;
}

