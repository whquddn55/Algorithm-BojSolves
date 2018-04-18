#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 402

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, flow, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), flow(0), reverse(reverse) {}
};

vector<Edge> graph[MAX_V]; // vertex의 각 Edge를 보관하는 vector
int level[MAX_V]; // vertex의 level 보관
int iter[MAX_V]; // 각 vertex의 Edge 방문개수 보관

int n, m;
bool checked[MAX_V][MAX_V];

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
	for (int i = 0; i < MAX_V; i++)
		fill(checked[i], checked[i] + MAX_V, true);

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + 200;
	int sink = rightStart + 200;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, x, y, v;
		cin >> a >> x >> y >> v;
		
		for (int i = x; i <= y; i++) {
			if (a == 1)
				for (int j = v + 1; j <= n; j++)
					checked[i][j] = false;
			else
				for (int j = 1; j < v; j++)
					checked[i][j] = false;
		}

		for (int i = 1; i < x; i++)
			checked[i][v] = false;
		for (int i = y + 1; i <= n; i++)
			checked[i][v] = false;
	}

	for (int left = 0; left < n; left++) {
		addEdge(source, leftStart + left, 1);
		for (int right = 0; right < n; right++)
			if (checked[right + 1][left + 1])
				addEdge(leftStart + left, rightStart + right, 1);
	}
	for (int right = 0; right < n; right++) 
		addEdge(rightStart + right, sink, 1);

	if (maxFlow(source, sink) == n) {
		for (int right = 0; right < n; right++)
			for (Edge& e : graph[rightStart + right])
				if (e.to != sink && e.flow == -1)
					cout << e.to << ' ';
	}
	else
		cout << -1 << endl;
	

	return 0;
}
