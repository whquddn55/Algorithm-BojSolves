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
using std::ios_base;
using std::cin;
using std::cout;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

struct Edge {
	int to, capacity, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), reverse(reverse) {}
};

vector<vector<Edge>> graph;
vector<int> level;
vector<int> iter;

int n, m, k;
int v;

void bfs(int s) {
	fill(level.begin(), level.end(), -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (Edge& e : graph[v]) {
			if (e.capacity > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				q.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t)
		return f;
	for (int& i = iter[v]; i < graph[v].size(); i++) {
		Edge& e = graph[v][i];
		if (e.capacity > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.capacity));
			if (d > 0) {
				e.capacity -= d;
				graph[e.to][e.reverse].capacity += d;
				return d;
			}
		}
	}

	return 0;
}

int maxFlow(int s, int t) {
	int flow = 0;
	while (true) {
		bfs(s);
		if (level[t] < 0)
			return flow;
		fill(iter.begin(), iter.end(), 0);
		int f;
		while ((f = dfs(s, t, INF)) > 0)
			flow += f;
	}
	return flow;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> k;
	v = n + m + 3;
	graph.resize(v);
	level.resize(v);
	iter.resize(v);

	graph[0].emplace_back(1, k, graph[1].size()); // 0 -> 1
	graph[1].emplace_back(0, 0, graph[0].size() - 1);

	for (int i = 2; i < n + 2; i++) { // 0 -> n * 2 + 1, 1 -> n * 2 + 1
		graph[0].emplace_back(i, 1, graph[i].size());
		graph[i].emplace_back(0, 0, graph[0].size() - 1);
		graph[1].emplace_back(i, k, graph[i].size());
		graph[i].emplace_back(1, 0, graph[1].size() - 1);
	}

	for (int i = 2; i < n + 2; i++) { // left to right
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int t;
			cin >> t;
			graph[i].emplace_back(t + n + 1, 1, graph[t + n + 1].size());
			graph[t + n + 1].emplace_back(i, 0, graph[i].size() - 1);
		}
	}

	for (int i = n + 2; i < v - 1; i++) { // right to sink
		graph[i].emplace_back(v - 1, 1, graph[v - 1].size());
		graph[v - 1].emplace_back(i, 0, graph[i].size() - 1);
	}

	cout << maxFlow(0, v - 1);

	return 0;
}
