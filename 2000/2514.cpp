#include <bits/stdc++.h>
using namespace std;

int m, k;
int arr[8][8];
int sum[8][8];
int B[8][8];
char result[8][8];

int main() {
	scanf("%d %d", &m, &k);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 8; j++) {
			int sum = 0;
			for (int k = 0; k < 8; k++) {
				sum += arr[i][k];
				sum += arr[k][j];
			}
			sum -= arr[i][j];

			if ((sum % 2) != (m % 2))
				result[i][j] = '-';
		}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			B[i][j] += m;
			if (result[i][j] == '-') {
				for (int k = 0; k < 8; k++) {
					B[i][k]--;
					B[k][j]--;
				}
				B[i][j]++;
			}
		}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			int sum1 = 0;
			for (int k = 0; k < 8; k++) {
				sum1 += B[i][k];
				sum1 += B[k][j];
			}
			sum1 -= B[i][j];

			int sum2 = 0;
			for (int k = 0; k < 8; k++) {
				sum2 += arr[i][k];
				sum2 += arr[k][j];
			}
			sum2 -= arr[i][j];

			if ((sum1 % 4) != (sum2 % 4))
				result[i][j] = '+';
		}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (result[i][j] == 0)
				printf(". ");
			else
				printf("%c ", result[i][j]);
		printf("\n");
	}

	return 0;
}