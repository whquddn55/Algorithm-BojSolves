#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr1[10], arr2[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr1[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr2[i]);

	int score[2] = { 0, 0 };
	int lastWin = -1;
	for (int i = 0; i < 10; i++) {
		if (arr1[i] > arr2[i]) {
			score[0] += 3;
			lastWin = 0;
		}
		else if (arr1[i] < arr2[i]) {
			score[1] += 3;
			lastWin = 1;
		}
		else {
			score[0]++;
			score[1]++;
		}
	}

	printf("%d %d\n", score[0], score[1]);
	if (score[0] == score[1]) {
		if (lastWin == -1)
			printf("%c\n", 'D');
		else
			printf("%c\n", 'A' + lastWin);
	}
	else
		printf("%c\n", 'A' + (score[0] < score[1]));

	return 0;
}