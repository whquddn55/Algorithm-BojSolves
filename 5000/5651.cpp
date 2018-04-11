#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101
#define MAX_V 301

struct Edge {
	int to, capacity, flow, rev;

	Edge(int to, int capacity, int rev) 
		: to(to), capacity(capacity), rev(rev), flow(0) { }
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
			if ((e.capacity - e.flow) > 0 && level[e.to] < 0) {
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
		if ((e.capacity - e.flow) > 0 && level[here] < level[e.to]) {
			int d = dfs(e.to, to, min(flow, (e.capacity - e.flow)));
			if (d > 0) {
				e.flow += d;
				graph[e.to][e.rev].flow -= d;
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

void addEdge(int from, int to, int capacity) {
	graph[from].emplace_back(to, capacity, graph[to].size());
	graph[to].emplace_back(from, 0, graph[from].size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < MAX_V; i++)
			graph[i].clear();

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int from, to, cap;
			cin >> from >> to >> cap;
			addEdge(from, to, cap);
		}

		maxFlow(1, n);

		int ans = 0;
		for (int i = 0; i <= n; i++)
			for (Edge& e : graph[i])
				if (e.capacity && e.capacity == e.flow) {
					memset(level, -1, sizeof(level));
					queue<int> q;
					q.push(i);
					level[i] = 0;

					while (!q.empty()) {
						int here = q.front();
						q.pop();

						for (Edge& e : graph[here]) {
							if ((e.capacity - e.flow) > 0 && level[e.to] < 0) {
								level[e.to] = level[here] + 1;
								q.push(e.to);
							}
						}
					}

					if (level[e.to] == -1)
						ans++;
				}
		cout << ans << endl;
	}

	return 0;
}
