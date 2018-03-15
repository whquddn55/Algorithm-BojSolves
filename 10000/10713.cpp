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

struct Data {
	int a, b, c;
};

int n, m;
vector<int> arr;
vector<Data> costs;
vector<int> numOfVisited;
vector<vector<int>> ends;

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(m);
	costs.resize(n);
	numOfVisited.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++)
		scanf("%d %d %d", &costs[i].a, &costs[i].b, &costs[i].c);

	ends.resize(n + 1);
	for (int i = 0; i < m - 1; i++) {
		int here = min(arr[i], arr[i + 1]);
		int next = max(arr[i], arr[i + 1]);

		ends[here].push_back(next);
	}

	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		cnt += ends[i].size();
		while (!pq.empty() && pq.top() == i) {
			pq.pop();
			cnt--;
		}
		for (int j = 0; j < ends[i].size(); j++)
			pq.push(ends[i][j]);

		numOfVisited[i] = cnt;
	}

	ll result = 0;
	for (int i = 1; i <= n; i++)
		if (numOfVisited[i])
			result += min(costs[i].a * (ll)numOfVisited[i], costs[i].c + costs[i].b * (ll)numOfVisited[i]);

	printf("%lld\n", result);

	return 0;
}