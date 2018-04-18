#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 100003

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, flow, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), flow(0), reverse(reverse) {}
};

vector<Edge> graph[MAX_V]; // vertex의 각 Edge를 보관하는 vector
int level[MAX_V]; // vertex의 level 보관
int iter[MAX_V]; // 각 vertex의 Edge 방문개수 보관

int n, m;

void bfs(int s) {
	fill(level, level + MAX_V, -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (Edge& e : graph[v]) {
			if (e.capacity - e.flow > 0 && level[e.to] < 0) {
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
		if (e.capacity - e.flow > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.capacity - e.flow));
			if (d > 0) {
				e.flow += d;
				graph[e.to][e.reverse].flow -= d;
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
		fill(iter, iter + MAX_V, 0);
		int f;
		while ((f = dfs(s, t, INF)) > 0)
			flow += f;
	}
	return flow;
}

void addEdge(int from, int to, int capacity) {
	graph[from].emplace_back(to, capacity, graph[to].size());
	graph[to].emplace_back(from, 0, graph[from].size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> m >> n;
	int source = 0;
	int sink = (m + 1) * n + 1;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		addEdge(source, 1 + i, a);
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		vector<int> arr;
		while (t--) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}
		for (int j = 0; j < arr.size(); j++) {
			addEdge((m + 1) * i + arr[j], (m + 1) * (i + 1), INF);
			for (int k = 0; k < arr.size(); k++)
				if (j != k)
					addEdge((m + 1) * i + arr[j], (m + 1) * (i + 1) + arr[k], INF);
		}
		if (i != n - 1)
			for (int j = 0; j < m; j++)
				addEdge((m + 1) * i + (j + 1), (m + 1) * (i + 1) + (j + 1), INF);

		int tmp;
		cin >> tmp;
		addEdge((m + 1) * (i + 1), sink, tmp);
	}

	cout << maxFlow(source, sink) << endl;
	

	return 0;
}
