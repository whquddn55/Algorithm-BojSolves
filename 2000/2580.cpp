#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int board[9][9];
vector<pii> blank;
bool horizon[9][10];
bool vertical[9][10];
bool square[9][10];

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

void get(int idx) {
	if (idx == blank.size()) {
		print();
		exit(0);
	}

	int y = blank[idx].first;
	int x = blank[idx].second;
	for (int i = 1; i <= 9; i++) {
		if (!horizon[y][i] && !vertical[x][i] && !square[(y / 3) * 3 + (x / 3)][i]) {
			horizon[y][i] = vertical[x][i] = square[(y / 3) * 3 + (x / 3)][i] = true;
			board[y][x] = i;
			get(idx + 1);
			horizon[y][i] = vertical[x][i] = square[(y / 3) * 3 + (x / 3)][i] = false;
			board[y][x] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0)
				blank.emplace_back(i, j);
		}

	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++) {
			horizon[i][board[i][j]] = true;
			vertical[i][board[j][i]] = true;
		}
	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++) 
			square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;

	get(0);

	return 0;
}
