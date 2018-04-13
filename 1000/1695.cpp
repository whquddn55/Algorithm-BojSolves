#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 5001

int n;
int arr[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int getdp(int idx1, int idx2) {
	if (idx1 >= idx2)
		return 0;
	
	int &ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	if (arr[idx1] != arr[idx2])
		return ret = min(getdp(idx1 + 1, idx2) + 1, getdp(idx1, idx2 - 1) + 1);
	else
		return ret = getdp(idx1 + 1, idx2 - 1);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << getdp(0, n - 1) << endl;

	return 0;
}
