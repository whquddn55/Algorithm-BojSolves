#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > arr;

void dfs(int y, int x, int height, vector<vector<bool> >& visited) {
	visited[y][x] = true;

	int dy[] = { 0, -1, 0, 1 };
	int dx[] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || ny < 0 || nx >= n || nx < 0)
			continue;
		if (arr[ny][nx] <= height)
			continue;
		if (visited[ny][nx])
			continue;
		
		dfs(ny, nx, height, visited);
	}
}

int dfsAll(int maxValue) {
	int result = 0;
	for (int i = 0; i <= maxValue; i++) {
		vector<vector<bool> > visited(n);
		for (int j = 0; j < n; j++)
			visited[j].resize(n, false);

		int cnt = 0;
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < n; k++)
				if (!visited[j][k] && arr[j][k] > i) {
					dfs(j, k, i, visited);
					cnt++;
				}
		result = max(result, cnt);
	}

	return result;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);

	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			maxValue = max(maxValue, arr[i][j]);
		}
	}

	printf("%d\n", dfsAll(maxValue));

	return 0;
}