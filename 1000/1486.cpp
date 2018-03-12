#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::make_pair;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m, t, d;
vector<vector<int>> arr;
vector<vector<int>> dist;

int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

void floyd() {
	for (int k = 0; k < n * m; k++)
		for (int i = 0; i < n * m; i++)
			for (int j = 0; j < n * m; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
	scanf("%d %d %d %d", &n, &m, &t, &d);

	dist.resize(n * m);
	for (int i = 0; i < n * m; i++) {
		dist[i].resize(n * m, INF);
	}

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(m);
		for (int j = 0; j < m; j++) {
			char t;
			scanf(" %c", &t);
			if (t >= 'A' && t <= 'Z')
				arr[i][j] = t - 'A';
			else
				arr[i][j] = t - 'a' + 26;

		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int hereIdx = i * m + j;
			for (int k = 0; k < 4; k++) {
				int nextY = i + dy[k];
				int nextX = j + dx[k];
				int nextIdx = nextY * m + nextX;

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
					continue;
				if (abs(arr[i][j] - arr[nextY][nextX]) > t)
					continue;
				if (arr[i][j] >= arr[nextY][nextX])
					dist[hereIdx][nextIdx] = 1;
				else 
					dist[hereIdx][nextIdx] = (arr[i][j] - arr[nextY][nextX]) * (arr[i][j] - arr[nextY][nextX]);
			}
		}

	floyd();
	
	int result = arr[0][0];
	for (int i = 0; i < n * m; i++) {
		int hereY = i / m;
		int hereX = i % m;
		
		if (dist[0][i] + dist[i][0] <= d)
			result = max(result, arr[hereY][hereX]);
	}

	printf("%d\n", result);

	return 0;
}