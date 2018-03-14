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
vector<pii> arr;

bool cmpByY(const pii& a, const pii& b) {
	return a.second < b.second;
}

int dist(const pii& a, const pii& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int closestPair(int n, int idx) {
	if (n == 2)
		return dist(arr[idx], arr[idx + 1]);
	if (n == 3)
		return min({ dist(arr[idx], arr[idx + 1]), dist(arr[idx + 1], arr[idx + 2]), dist(arr[idx + 2], arr[idx]) });
	
	int line = (arr[idx + n / 2 - 1].first + arr[idx + n / 2].first) / 2;
	int d = min(closestPair(n / 2, idx), closestPair(n - n / 2, idx + n / 2));

	vector<pii> mid;
	for (int i = 0; i < n; i++) {
		int t = line - arr[idx + i].first;
		if (t * t <= d)
			mid.push_back(arr[idx + i]);
	}

	sort(mid.begin(), mid.end(), cmpByY);
	
	for (int i = 0; i < mid.size(); i++) {
		for (int j = i + 1; j < mid.size() && j <= i + 6; j++)
			d = min(d, dist(mid[i], mid[j]));
	}

	return d;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	sort(arr.begin(), arr.end());
	
	printf("%d\n", closestPair(n, 0));

	return 0;
}