#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

struct Edge {
	int to, capacity, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), reverse(reverse) {}
};

struct Data {
	int a, b, c;
};

int v;
vector<vector<Edge>> graph;
vector<int> level;
vector<int> iter;

int n;
vector<Data> arr;

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

	cin >> n;
	arr.resize(n);
	v = n * 2 + 2;
	graph.resize(v);
	level.resize(v);
	iter.resize(v);

	for (int i = 0; i < n; i++)
		cin >> arr[i].a >> arr[i].b >> arr[i].c;

	int source = 0;
	int leftStart = 1;
	int rightStart = n + 1;
	int sink = v - 1;
	for (int left = 0; left < n; left++) { // source to left
		graph[source].emplace_back(leftStart + left, 2, graph[leftStart + left].size());
		graph[leftStart + left].emplace_back(source, 0, graph[source].size() - 1);
	}

	for (int left = 0; left < n; left++) { // left to right
		for (int right = 0; right < n; right++) {
			if ((left != right) && 
				(arr[left].a >= arr[right].a && arr[left].b >= arr[right].b && arr[left].c >= arr[right].c)) {

				if ((arr[left].a == arr[right].a && arr[left].b == arr[right].b && arr[left].c == arr[right].c) && (left > right))
					continue;
				graph[leftStart + left].emplace_back(rightStart + right, 1, graph[rightStart + right].size());
				graph[rightStart + right].emplace_back(leftStart + left, 0, graph[leftStart + left].size() - 1);
			}
		}
	}

	for (int right = 0; right < n; right++) {
		graph[rightStart + right].emplace_back(sink, 1, graph[sink].size());
		graph[sink].emplace_back(rightStart + right, 0, graph[rightStart + right].size() - 1);
	}
  
	cout << n - maxFlow(0, sink);

	return 0;
}
