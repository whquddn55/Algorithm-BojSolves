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
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<vector<int>> arr;

int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

bool dicide(int minValue, int diff) {
	if (arr[0][0] < minValue)
		return false;
	if ((arr[0][0] - minValue) > diff)
		return false;
	queue<pii> q;
	q.emplace(0, 0);
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[0][0] = true;
	
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();

		if (hereY == n - 1 && hereX == n - 1)
			return true;

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (arr[nextY][nextX] < minValue)
				continue;
			if ((arr[nextY][nextX] - minValue) > diff)
				continue;

			q.emplace(nextY, nextX);
			visited[nextY][nextX] = true;
		}
	}

	return false;
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;
	while (left <= right) {
		int mid = (left + right) / 2;
		bool check = false;
		for (int i = 0; i <= 200; i++) { // bfs의 minValue
			check = dicide(i, mid);
			if (check) 
				break;
		}
		//printf("%d %d %d\n", left, right, mid);
		if (check)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	int minValue = INF, maxValue = 0;
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			minValue = min(minValue, arr[i][j]);
			maxValue = max(maxValue, arr[i][j]);
		}
	}

	printf("%d\n", binarySearch(0, maxValue - minValue));

	return 0;
}