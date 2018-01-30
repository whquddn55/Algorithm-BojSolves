#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

char arr[15][15];

int main() {
	for (int i = 0; i < 5; i++) {
		char temp;
		int j = 0;
		while (scanf("%c", &temp) != EOF) {
			if (temp == '\n')
				break;
			arr[i][j] = temp;
			j++;
		}
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == 0)
				continue;
			printf("%c", arr[j][i]);
		}
	}
	printf("\n");

	return 0;
}