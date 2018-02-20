#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<vector<bool> > board;
int result = 0;

int main() {
	board.resize(101);
	for (int i = 0; i <= 100; i++)
		board[i].resize(101, false);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int i = x; i < x + 10; i++)
			for (int j = y; j < y + 10; j++)
				board[j][i] = true;
	}
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++) {
			if (board[i][j]) {
				int dy[] = { 0, -1, 1, 0 };
				int dx[] = { -1, 0, 0, 1 };
				for (int k = 0; k < 4; k++) {
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					if (nextY < 0 || nextX < 0 || nextY > 100 || nextX > 100)
						continue;
					if (!board[nextY][nextX])
						result++;
				}
			}
		}

	printf("%d\n", result);

	return 0;
}