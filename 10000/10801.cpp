#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

vector<int> arrA(10);
vector<int> arrB(10);

int main() {
	for (int i = 0; i < 10; i++)
		scanf("%d", &arrA[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &arrB[i]);

	int aWins = 0;
	int bWins = 0;
	for (int i = 0; i < 10; i++) {
		if (arrA[i] > arrB[i])
			aWins++;
		else if (arrB[i] > arrA[i])
			bWins++;
	}

	printf("%c\n", (aWins > bWins) ? ('A') : ((bWins > aWins) ? 'B' : 'D'));

	return 0;
}