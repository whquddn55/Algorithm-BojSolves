#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXSIZE 2500

bool dp[MAXSIZE][MAXSIZE]; // i 부터 j까지 팰린드롬인가?
int result[MAXSIZE]; // i까지의 원소로 구성된 부분 팰린드롬의 최소 갯수

int main() {
	string str;
	cin >> str;

	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (str[i] == str[i + 1])
			dp[i][i + 1] = true;
		dp[i][i] = true;
	}

	for (int i = 0; i < size; i++)
		result[i] = 987654321;
	result[0] = 1;

	for (int dif = 2; dif < size; dif++) {
		for (int start = 0; start + dif < size; start++) {
			if (str[start] == str[start + dif] && dp[start + 1][start + dif - 1] == true)
				dp[start][start + dif] = true;
		}
	} // 팰린드롬 dp완성

	for (int end = 0; end < size; end++) {
		for (int start = 0; start <= end; start++) {
			if (dp[start][end] == true) 
				result[end] = min(result[end], start - 1 < 0 ? 1 : (result[start - 1] + 1));
		}
	}

	cout << result[size - 1] << endl;


	return 0;
}