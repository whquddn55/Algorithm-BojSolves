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
vector<vector<int>> capacity; // 0 : source, n + 1 : sink
vector<vector<int>> flow;

int v;

int networkFlow(int source, int sink) {
	int totalFlow = 0;
	while (true) {
		vector<int> parent(v, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);

		while (!q.empty()) {
			int here = q.front();
			q.pop();
			
			for (int there = 0; there < v; there++)
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}

		if (parent[sink] == -1) break;

		int amount = INF;
		for (int p = sink; p != source; p = parent[p])
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);

		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int main() {
	scanf("%d %d", &n, &m);
	v = n + m + 2;
	capacity.resize(v);
	flow.resize(v);
	for (int i = 0; i < v; i++) {
		capacity[i].resize(n + m + 2, 0);
		flow[i].resize(n + m + 2, 0);
	}

	for (int i = 1; i <= n; i++) // source to cow
		capacity[0][i] = 1;

	for (int i = 1; i <= n; i++) { // cow to cage
		int s;
		scanf("%d", &s);
		for (int j = 0; j < s; j++) {
			int t;
			scanf("%d", &t);
			capacity[i][t + n] = 1;
		}
	}

	for (int i = 1; i <= m; i++) // cage to sink
		capacity[i + n][n + m + 1] = 1;

	printf("%d\n", networkFlow(0, n + m + 1));

	return 0;
}
