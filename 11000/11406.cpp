#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101
#define MAX_V 203

struct Edge {
	int to, capacity, rev;

	Edge(int to, int capacity, int rev) 
		: to(to), capacity(capacity), rev(rev) { }
};

int n, m;

int level[MAX_V];
int iter[MAX_V];
vector<Edge> graph[MAX_V];

void bfs(int start) {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(start);
	level[start] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (Edge& e : graph[here]) {
			if (e.capacity > 0 && level[e.to] < 0) {
				level[e.to] = level[here] + 1;
				q.push(e.to);
			}
		}
	}
}

int dfs(int here, int to, int flow) {
	if (here == to)
		return flow;
	for (int& i = iter[here]; i < graph[here].size(); i++) {
		Edge& e = graph[here][i];
		if (e.capacity > 0 && level[here] < level[e.to]) {
			int d = dfs(e.to, to, min(flow, e.capacity));
			if (d > 0) {
				e.capacity -= d;
				graph[e.to][e.rev].capacity += d;
				return d;
			}
		}
	}

	return 0;
}

int maxFlow(int here, int to) {
	int flow = 0;
	while (true) {
		bfs(here);
		if (level[to] < 0)
			return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(here, to, INF)) > 0)
			flow += f;
	}
	return flow;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + m;
	int sink = rightStart + n;

	for (int right = 0; right < n; right++) {
		int a;
		cin >> a;
		int from = rightStart + right;
		graph[from].emplace_back(sink, a, graph[sink].size());
		graph[sink].emplace_back(from, 0, graph[from].size() - 1);
	}

	for (int left = 0; left < m; left++) {
		int a;
		cin >> a;
		int to = leftStart + left;
		graph[source].emplace_back(to, a, graph[to].size());
		graph[to].emplace_back(source, 0, graph[source].size() - 1);
	}

	for (int left = 0; left < m; left++)
		for (int right = 0; right < n; right++) {
			int a;
			cin >> a;
			if (!a)
				continue;

			int from = leftStart + left;
			int to = rightStart + right;
			graph[from].emplace_back(to, a, graph[to].size());
			graph[to].emplace_back(from, 0, graph[from].size() - 1);
		}

	cout << maxFlow(source, sink) << endl;

	return 0;
}
