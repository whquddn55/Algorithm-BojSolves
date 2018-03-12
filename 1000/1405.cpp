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

int n;
vector<double> chances(4);
vector<vector<bool>> visited(30); // 영점 : (15, 15)
double result = 0.0;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

void get(int hereY, int hereX, int depth, double prob) {
	if (depth == n) {
		result += prob;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextY = hereY + dy[i];
		int nextX = hereX + dx[i];

		if (!visited[nextY][nextX]) {
			visited[nextY][nextX] = true;
			get(nextY, nextX, depth + 1, prob * chances[i]);
			visited[nextY][nextX] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; ++i) {
		scanf("%lf", &chances[i]);
		chances[i] /= 100;
	}
	for (int i = 0; i < 30; i++)
		visited[i].resize(30);

	visited[15][15] = true;
	get(15, 15, 0, 1.0);

	printf("%.10lf\n", result);

	return 0;
}