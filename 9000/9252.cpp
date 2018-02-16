#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define MAXSIZE 1001

int dp[MAXSIZE][MAXSIZE];
string str1, str2;
string result;

int getDp(int idx1, int idx2) {
	if (idx1 == str1.size() || idx2 == str2.size())
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	if (str1[idx1] == str2[idx2]) 
		return ret = getDp(idx1 + 1, idx2 + 1) + 1;
	else
		return ret = max(getDp(idx1 + 1, idx2), getDp(idx1, idx2 + 1));
}

void getLcsString(int idx1, int idx2) {
	if (dp[idx1][idx2] == -1)
		return;

	if (str1[idx1] == str2[idx2]) {
		result.push_back(str1[idx1]);
		getLcsString(idx1 + 1, idx2 + 1);
	}
	else if (dp[idx1 + 1][idx2] == dp[idx1][idx2])
		getLcsString(idx1 + 1, idx2);
	else
		getLcsString(idx1, idx2 + 1);
}

int main() {
	cin >> str1 >> str2;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", getDp(0, 0));

	getLcsString(0, 0);
	printf("%s\n", result.c_str());

	return 0;
}