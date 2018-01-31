#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int c, r, k;
vector<vector<bool> > visited;

int main() {
	scanf("%d %d", &c, &r);
	scanf("%d", &k);
	if (k > r * c)
		printf("0\n");
	else {
		visited.resize(r);
		for (int i = 0; i < r; i++)
			visited[i].resize(c);

		int dy[] = { -1, 0, 1, 0 };
		int dx[] = { 0, 1, 0, -1 };
		int idx = 0;
		int y = r - 1;
		int x = 0;
		for (int i = 1; i <= r * c; i++) {
			if (i == k) {
				printf("%d %d\n", x + 1, r - y);
				break;
			}

			visited[y][x] = true;

			int ny = y + dy[idx % 4];
			int nx = x + dx[idx % 4];
			if (ny >= r || ny < 0 || nx >= c || nx < 0 || visited[ny][nx])
				idx++;

			x += dx[idx % 4];
			y += dy[idx % 4];
		}
	}

	return 0;
}