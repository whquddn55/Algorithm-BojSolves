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

int n, m, s, v;
pair<double, double> mice[MAX_SIZE];
pair<double, double> hole[MAX_SIZE];

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
	
	cin >> n >> m >> s >> v;
	for (int i = 0; i < n; i++)
		cin >> mice[i].first >> mice[i].second;
	for (int i = 0; i < m; i++)
		cin >> hole[i].first >> hole[i].second;

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + n;
	int sink = rightStart + m;

	for (int left = 0; left < n; left++) {
		int to = leftStart + left;
		graph[source].emplace_back(to, 1, graph[to].size());
		graph[to].emplace_back(source, 0, graph[source].size() - 1);
	}

	for (int left = 0; left < n; left++)
		for (int right = 0; right < m; right++) {
			int from = leftStart + left;
			int to = rightStart + right;
			double dist = sqrt((mice[left].first - hole[right].first) * (mice[left].first - hole[right].first) + (mice[left].second - hole[right].second) * (mice[left].second - hole[right].second));
			if (dist <= s * v) {
				graph[from].emplace_back(to, 1, graph[to].size());
				graph[to].emplace_back(from, 0, graph[from].size() - 1);
			}
		}

	for (int right = 0; right < m; right++) {
		int from = rightStart + right;
		graph[from].emplace_back(sink, 1, graph[sink].size());
		graph[sink].emplace_back(from, 0, graph[from].size() - 1);
	}

	cout << n - maxFlow(source, sink) << endl;

	return 0;
}
