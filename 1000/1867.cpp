#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), reverse(reverse) {}
};

int v; // graph의 총 vertex 개수
vector<vector<Edge>> graph; // vertex의 각 Edge를 보관하는 vector
vector<int> level; // vertex의 level 보관
vector<int> iter; // 각 vertex의 Edge 방문개수 보관

int n, k;
vector<vector<char>> arr;

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

	cin >> n >> k;

	v = n * 2 + 2;
	graph.resize(v);
	iter.resize(v);
	level.resize(v);

	int source = 0;
	int sink = v - 1;

	for (int left = 1; left <= n; left++) {
		graph[source].emplace_back(left, 1, graph[left].size());
		graph[left].emplace_back(source, 0, graph[source].size());
	}

	for (int i = 0; i < k; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].emplace_back(to + n, 1, graph[to + n].size());
		graph[to + n].emplace_back(from, 0, graph[from].size() - 1);
	}

	for (int right = n + 1; right <= sink - 1; right++) {
		graph[right].emplace_back(sink, 1, graph[sink].size());
		graph[sink].emplace_back(right, 0, graph[right].size());
	}

	cout << maxFlow(source, sink) << endl;
	
	return 0;
}
