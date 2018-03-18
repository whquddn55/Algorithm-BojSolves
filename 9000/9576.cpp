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

int n, m;

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

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		v = n + m + 2; // vertex 개수 설정
		for (int i = 0; i < graph.size(); i++)
			graph[i].clear();
		graph.clear();
		level.clear();
		iter.clear();
		graph.resize(v); // graph의 크기를 vertex개수만큼
		level.resize(v); // level의 크기를 vertex개수만큼
		iter.resize(v); // iter의 크기를 vertex개수만큼

		int source = 0; // source의 vertex 번호
		int sink = v - 1; // sink의 vertex 번호
		int leftStart = 1;
		int rightStart = n + 1;

		for (int left = 0; left < n; left++) {
			graph[0].emplace_back(leftStart + left, 1, graph[leftStart + left].size());
			graph[leftStart + left].emplace_back(0, 0, graph[0].size() - 1);
		}

		for (int right = 0; right < m; right++) {
			int a, b;
			cin >> a >> b;

			for (int left = a; left <= b; left++) {
				graph[left].emplace_back(rightStart + right, 1, graph[rightStart + right].size());
				graph[rightStart + right].emplace_back(left, 0, graph[left].size() - 1);
			}
		}
		
		for (int right = 0; right < m; right++) {
			graph[rightStart + right].emplace_back(sink, 1, graph[sink].size());
			graph[sink].emplace_back(rightStart + right, 0, graph[rightStart + right].size() - 1);
		}
		
		cout << maxFlow(source, sink) << endl; // source에서 sink로의 maximalFlow 구함
	}

	return 0;
}
