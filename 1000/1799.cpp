#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'
#define MAXSIZE 100001

int n;
vector<vector<int>> arr;

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), reverse(reverse) {}
};

int v; // graph의 총 vertex 개수
vector<vector<Edge>> graph; // vertex의 각 Edge를 보관하는 vector
vector<int> level; // vertex의 level 보관
vector<int> iter; // 각 vertex의 Edge 방문개수 보관

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
	arr.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];
	
	v = n * 4;
	graph.resize(v);
	iter.resize(v);
	level.resize(v);

	for (int lb = 1; lb <= (n * 2 - 1); lb++) {
		graph[0].emplace_back(lb, 1, graph[lb].size());
		graph[lb].emplace_back(0, 0, graph[0].size() - 1);
	}

	for (int rb = (n * 2); rb <= v - 2; rb++) {
		graph[rb].emplace_back(v - 1, 1, graph[v - 1].size());
		graph[v - 1].emplace_back(rb, 0, graph[rb].size() - 1);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				int lb = (i + j) + 1;
				int rb = (j - i + n - 1) + (n * 2 - 1) + 1;
#ifdef DEBUG
				cout << lb << " to " << rb << endl;
#endif
				graph[lb].emplace_back(rb, 1, graph[rb].size());
				graph[rb].emplace_back(lb, 0, graph[lb].size() - 1);
			}
			else
				cnt++;
		}

	cout << maxFlow(0, v - 1) << endl;

	return 0;
}
