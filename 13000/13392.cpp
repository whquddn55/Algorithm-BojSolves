#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
string from, to;
int dp[100000][10];
vector<int> selected;

int getDp(int here, int added) {
	if (here == n)
		return 0;

	int& ret = dp[here][added];
	if (ret != -1)
		return ret;

	int num1 = (from[here] - '0' + added) % 10;
	int num2 = to[here] - '0';

	int left = (num1 > num2) ? (10 - (num1 - num2)) : (num2 - num1);
	int right = (num2 > num1) ? (10 - (num2 - num1)) : (num1 - num2);

	int leftValue = getDp(here + 1, (added + left) % 10) + left;
	int rightValue = getDp(here + 1, added) + right;

	if (leftValue > rightValue) {
		ret = rightValue;
		selected[here] = -right;
	}
	else {
		ret = leftValue;
		selected[here] = left;
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	cin >> from >> to;
	
	memset(dp, -1, sizeof(dp));
	selected.resize(n);
	printf("%d\n", getDp(0, 0));

	return 0;
}