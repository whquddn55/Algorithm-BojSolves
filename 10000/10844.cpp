#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 101

int n;
int dp[MAXSIZE][10]; // 길이가 i인 숫자 중 j를 끝 자리로 가지는 계단수의 개수

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1];
			else if (j == 9)
				dp[i][9] = dp[i - 1][8];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}

	int result = 0;
	for (int i = 0; i < 10; i++) 
		result = (result + dp[n][i]) % 1000000000;

	cout << result << endl;

	return 0;
}