#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 50 + 50 + 2

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, flow, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), flow(0), reverse(reverse) {}
};

int n;
int sum;

int source = 0;
int leftStart = 1;
int rightStart = leftStart + 50;
int sink = rightStart + 50;

vector<Edge> graph[MAX_V]; // vertex의 각 Edge를 보관하는 vector
int level[MAX_V]; // vertex의 level 보관
int iter[MAX_V]; // 각 vertex의 Edge 방문개수 보관

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

bool decide(int mid) { // mid이하로만 흘려줄 수 있는가?
	for (int i = 0; i < MAX_V; i++)
		for (Edge& e : graph[i]) {
			e.flow = 0;
			if (i >= leftStart && i < rightStart && e.to >= rightStart && e.to < sink) 
				e.capacity = mid;
		}
	int ret = maxFlow(source, sink);
	return ret == sum;
}

int binarySearch() {
	int left = 0, right = 1000;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (decide(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	decide(left);
	return left;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	
	for (int left = 0; left < n; left++) {
		int a;
		cin >> a;
		sum += a;
		addEdge(source, leftStart + left, a);
		for (int right = 0; right < n; right++)
			addEdge(leftStart + left, rightStart + right, a);
	}
	for (int right = 0; right < n; right++) {
		int a;
		cin >> a;
		addEdge(rightStart + right, sink, a);
	}

	cout << binarySearch() << endl;

	for (int i = 0; i < MAX_V; i++) {
		bool c = false;
		for (Edge& e : graph[i]) {
			if (i >= leftStart && i < rightStart && e.to >= rightStart && e.to < sink) {
				cout << e.flow << ' ';
				c = true;
			}
		}
		if (c)
			cout << endl;
	}

	return 0;
}
