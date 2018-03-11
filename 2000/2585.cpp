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

int n, k;
vector<pii> arr;

bool dicide(int mid) {
	vector<bool> visited(n, false);
	queue<pii> q; // first : index, second :cost;
	for (int i = 0; i < n; i++) {
		int cost = sqrt(arr[i].first * arr[i].first + arr[i].second * arr[i].second) * 10000;
		if ((cost / 100000 - (cost % 100000 == 0) + 1) <= mid) {
			if (arr[i].first == 10000 && arr[i].second == 10000)
				return true;
			q.emplace(i, 1);
			visited[i] = true;
		}
	}

	while (!q.empty()) {
		int here = q.front().first;
		int dist = q.front().second;
		int hereX = arr[here].first;
		int hereY = arr[here].second;
		q.pop();

		if (dist > k)
			break;

		for (int i = 0; i < n; i++) {
			int nextX = arr[i].first;
			int nextY = arr[i].second;
			if (visited[i])
				continue;
			
			int cost = sqrt((hereX - nextX) * (hereX - nextX) + (hereY - nextY) * (hereY - nextY)) * 10000;
			if ((cost / 100000 - (cost % 100000 == 0) + 1) <= mid) {
				if (nextX == 10000 && nextY == 10000) 
					return true;
				
				q.emplace(i, dist + 1);
				visited[i] = true;
			}
		}
	}

	return false;
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (dicide(mid)) 
			right = mid - 1;
		else 
			left = mid + 1;
		
	}
	return left;
}

int main() {
	scanf("%d %d", &n, &k);
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &arr[i].first, &arr[i].second);
	arr.emplace_back(10000, 10000);
	n++;
	
	printf("%d\n", binarySearch(0, 15000));
}