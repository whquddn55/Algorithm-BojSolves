#include <bits/stdc++.h>
using namespace std;

struct Data{
	int y, x;
	Data(int y, int x)
		: y(y), x(x) { }
};

vector<vector<char> > graph;
//vector<vector<bool> > visited;
vector<bool> alphabetVisited;
int r, c;
int result = 0;

void dfs(int hereY, int hereX, int cnt) {
	int alphabet = graph[hereY][hereX] - 'A';
	if (alphabetVisited[alphabet])
		return;

	alphabetVisited[alphabet] = true;
	result = max(result, cnt);

	int dy[] = { 0, -1, 0, 1 };
	int dx[] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; i++) {
		int ny = hereY + dy[i];
		int nx = hereX + dx[i];
		
		if (ny >= r || nx >= c || ny < 0 || nx < 0)
			continue;		
		if (alphabetVisited[graph[ny][nx] - 'A'])
			continue;

		dfs(ny, nx, cnt + 1);
	}

	alphabetVisited[alphabet] = false;
}

int main() {
	cin >> r >> c;

	graph.resize(r);
	//visited.resize(r);
	alphabetVisited.resize(26, false);
	for (int i = 0; i < r; i++) {
		graph[i].resize(c);
		//visited[i].resize(c, false);
		for (int j = 0; j < c; j++)
			cin >> graph[i][j];
	}

	dfs(0, 0, 1);
	cout << result << endl;

	return 0;
}