#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

string arr;
int dp[41];

int main() {
	cin >> arr;
	for (int i = 0; i < arr.size(); i++) arr[i] -= '0';
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0 && (i == 0 || (arr[i - 1] >= 4))) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0 && (i == 0 || arr[i - 1] <= 3)) {
			arr.erase(arr.begin() + i);
			arr[i - 1] *= 10;
		}
	}

	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i <= 40; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	

	ll ret = 1;
	int cnt = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		if ((arr[i] * 10 + arr[i + 1] <= 34) && arr[i + 1] <= 9) {
			cnt++;
		}
		else {
			ret *= dp[cnt];
			cnt = 0;
		}
	}
	ret *= dp[cnt];
	printf("%d\n", ret);

	return 0;

}
