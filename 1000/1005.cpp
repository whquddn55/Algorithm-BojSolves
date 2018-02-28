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

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, k;
vector<vector<int>> edges;
vector<int> income;
vector<int> cost;
int w;

void topologicalSort() {
	priority_queue<int, vector<int>, greater<int>> q;
	vector<int> result(n + 1, 0);

	for (int i = 1; i <= n; i++) 
		if (income[i] == 0) {
			q.push(i);
			result[i] = cost[i];
		}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			printf("-123\n");
			return;
		}

		int here = q.top();
		q.pop();

		for (int j = 0; j < edges[here].size(); j++) {
			int next = edges[here][j];
			income[next]--;
			result[next] = max(result[next], cost[next] + result[here]);
			if (income[next] == 0) 
				q.push(next);
			
		}
	}

	printf("%d\n", result[w]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		cost.clear();
		income.clear();
		edges.clear();
		cost.resize(n + 1, 0);
		income.resize(n + 1, 0);
		edges.resize(n + 1);

		for (int i = 1; i <= n; i++)
			scanf("%d", &cost[i]);

		while (k--) {
			int from, to;
			scanf("%d %d", &from, &to);
			edges[from].push_back(to);
			income[to]++;
		}
		scanf("%d", &w);

		topologicalSort();
	}

	return 0;

}
