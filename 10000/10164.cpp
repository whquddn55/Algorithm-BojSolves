#include <iostream>
#include <vector>

using namespace std;
#define MAXSIZE 15

vector<vector<int> > graph;


int main() {
	int n, m;
	cin >> n >> m;

	graph.resize(n);
	for (int i = 0; i < n; i++)
		graph[i].resize(m, 0);

	int k;
	cin >> k;

	int y, x;

	if (k == 0) {
		y = n - 1;
		x = m - 1;
	}
	else {
		y = (k - 1) / m;
		x = (k - y * m) - 1;
	}

	for (int i = 0; i <= y; i++)
		graph[i][0] = 1;
	for (int i = 0; i <= x; i++)
		graph[0][i] = 1;

	for (int i = 1; i <= y; i++)
		for (int j = 1; j <= x; j++)
			graph[i][j] = graph[i][j - 1] + graph[i - 1][j];

	for (int i = y; i < n; i++)
		graph[i][x] = graph[y][x];
	for (int i = x; i < m; i++)
		graph[y][i] = graph[y][x];

	for (int i = y + 1; i < n; i++)
		for (int j = x + 1; j < m; j++)
			graph[i][j] = graph[i][j - 1] + graph[i - 1][j];

	cout << graph[n - 1][m - 1] << endl;

	return 0;
}
