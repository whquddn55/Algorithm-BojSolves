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

int n, m;
vector<vector<int>> arr;
vector<pii> cnt;

void getChild(int start) {
	vector<bool> visited(n + 1, false);

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < arr[here].size(); i++) {
			if (visited[arr[here][i]])
				continue;

			q.push(arr[here][i]);

			visited[arr[here][i]] = true;
			cnt[arr[here][i]].second++;
			cnt[start].first++;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		arr[from].emplace_back(to);
	}

	cnt.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getChild(i);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i].first > n / 2 || cnt[i].second > n / 2)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}