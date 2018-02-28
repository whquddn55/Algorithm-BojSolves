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
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
vector<vector<int>> edges;
vector<int> income;

void topologicalSort() {
	priority_queue<int, vector<int>, greater<int>> q;
	vector<int> result;

	for (int i = 1; i <= n; i++)
		if (income[i] == 0)
			q.push(i);

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			printf("0\n");
			return;
		}

		int here = q.top();
		q.pop();

		result.push_back(here);

		for (int j = 0; j < edges[here].size(); j++) {
			int next = edges[here][j];
			income[next]--;
			if (income[next] == 0)
				q.push(next);
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);
}

int main() {
	scanf("%d %d", &n, &m);
	edges.resize(n + 1);
	income.resize(n + 1, 0);

	while (m--) {
		int from, to;
		scanf("%d %d", &from, &to);

		edges[from].push_back(to);
		income[to]++;
	}

	topologicalSort();

	
	return 0;

}
