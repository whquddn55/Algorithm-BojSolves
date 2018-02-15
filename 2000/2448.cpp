#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
bool arr[4000][8000];

void get(int y1, int x1, int dy, int dx) {
	if (dy == 3) {
		arr[y1][x1 + 2] = true;
		arr[y1 + 1][x1 + 1] = true;
		arr[y1 + 1][x1 + 3] = true;
		for (int i = 0; i < 5; i++)
			arr[y1 + 2][x1 + i] = true;
		return;
	}
	

	get(y1, x1 + dx / 4, dy / 2, dx / 2);
	get(y1 + dy / 2, x1, dy / 2, dx / 2);
	get(y1 + dy / 2, x1 + dx / 2, dy / 2, dx / 2);
}

int main() {
	scanf("%d", &n);

	get(0, 0, n, n * 2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++)
			printf("%c", arr[i][j] ? '*' : ' ');
		printf("\n");
	}

	return 0;
}