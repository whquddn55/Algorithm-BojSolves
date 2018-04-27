#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 101
#define MAX_V 20001

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, flow, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), flow(0), reverse(reverse) {}
};

vector<Edge> graph[MAX_V]; // vertex의 각 Edge를 보관하는 vector
int level[MAX_V]; // vertex의 level 보관
int iter[MAX_V]; // 각 vertex의 Edge 방문개수 보관

int n, m;
char arr[MAX_N][MAX_N];

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

	cin >> n >> m;

	int source, sink;

	int dy[] = { 0, -1, 1, 0 };
	int dx[] = { -1, 0, 0, 1 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'K') 
				source = i * m + j;
			else if (arr[i][j] == 'H')
				sink = i * m + j;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'K')
				for (int k = 0; k < 4; k++) {
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
						continue;
					if (arr[nextY][nextX] == 'H') {
						cout << -1 << endl;
						return 0;
					}
				}
		}

	for (int hereY = 0; hereY < n; hereY++)
		for (int hereX = 0; hereX < m; hereX++) 
			for (int i = 0; i < 4; i++) {
				int nextY = hereY + dy[i];
				int nextX = hereX + dx[i];

				if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
					continue;
				if (arr[nextY][nextX] == '#')
					continue;

				addEdge(hereY * m + hereX + 10000, nextY * m + nextX, 1);
		}

	for (int i = 0; i < n * m; i++)
		addEdge(i, i + 10000, 1);

	cout << maxFlow(source + 10000, sink) << endl; // source에서 sink로의 maximalFlow 구함

	return 0;
}
