#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
int board[5][5];

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &board[i][j]);

	for (int i = 1; i <= 25; i++) {
		int number;
		scanf("%d", &number);
		for (int j = 0; j < 5; j++) {
			bool check = false;
			for (int k = 0; k < 5; k++)
				if (board[j][k] == number) {
					board[j][k] = -1;
					check = true;
				}
			if (check)
				break;
		}

		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			bool check = true;
			for (int k = 0; k < 5; k++)  {
				if (board[j][k] != -1) {
					check = false;
					break;
				}
			}
			if (check)
				cnt++;
		}
		for (int j = 0; j < 5; j++) {
			bool check = true;
			for (int k = 0; k < 5; k++) {
				if (board[k][j] != -1) {
					check = false;
					break;
				}
			}
			if (check)
				cnt++;
		}
		bool check = true;
		for (int j = 0; j < 5; j++)
			if (board[j][j] != -1) {
				check = false;
				break;
			}
		if (check)
			cnt++;

		check = true;
		for (int j = 0; j < 5; j++)
			if (board[4 - j][j] != -1) {
				check = false;
				break;
			}
		if (check)
			cnt++;

		if (cnt >= 3) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}
