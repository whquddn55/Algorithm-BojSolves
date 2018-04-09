#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101
#define MAX_V 20001

struct Edge {
	int to, capacity, rev;

	Edge(int to, int capacity, int rev) 
		: to(to), capacity(capacity), rev(rev) { }
};

int n, m;
int arr[MAX_SIZE][MAX_SIZE];
int r[MAX_SIZE][MAX_SIZE];
int c[MAX_SIZE][MAX_SIZE];

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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int cnt = 1;
	bool check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				if (check) {
					cnt++;
					check = false;
				}
			}
			else if (arr[i][j] == 0) {
				r[i][j] = cnt;
				check = true;
			}
		}
		if (check) {
			cnt++;
			check = false;
		}
	}

	int rightStart = cnt;

	check = false;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 2) {
				if (check) {
					cnt++;
					check = false;
				}
			}
			else if (arr[i][j] == 0) {
				c[i][j] = cnt;
				check = true;
			}
		}
		if (check) {
			cnt++;
			check = false;
		}
	}

	int source = 0;
	int sink = cnt + 1;
	int leftStart = 1;

	for (int left = 0; left < (rightStart - leftStart); left++) {
		int to = leftStart + left;
		graph[source].emplace_back(to, 1, graph[to].size());
		graph[to].emplace_back(source, 0, graph[source].size());
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2 || arr[i][j] == 1)
				continue;

			graph[r[i][j]].emplace_back(c[i][j], 1, graph[c[i][j]].size());
			graph[c[i][j]].emplace_back(r[i][j], 0, graph[r[i][j]].size() - 1);
		}
	}

	for (int right = 0; right < (sink - rightStart); right++) {
		int from = rightStart + right;
		graph[from].emplace_back(sink, 1, graph[sink].size());
		graph[sink].emplace_back(from, 0, graph[from].size());
	}

	cout << maxFlow(source, sink) << endl;

	return 0;
}
