#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 500

int n;
vector<vector<int> > graph;

int dp[MAXSIZE][MAXSIZE]; // (i, j)에서 살수 있는 최대 일 수;

int dfs(int y, int x) {
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 1;

	int dy[] = { 0, -1, 0, 1 };
	int dx[] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];	
		
		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;

		if (graph[y][x] >= graph[ny][nx])
			continue;

		ret = max(ret, dfs(ny, nx) + 1);
	}

	return ret;
}

int main() {
	cin >> n;

	graph.resize(n);
	for (int i = 0; i < n; i++) {
		graph[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	memset(dp, -1, sizeof(dp));
	int result = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
				result = max(result, dfs(i, j));

	cout << result << endl;

	return 0;
}