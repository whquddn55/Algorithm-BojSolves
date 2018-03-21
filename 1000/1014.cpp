#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), reverse(reverse) {}
};

int v; // graph의 총 vertex 개수
vector<vector<Edge>> graph; // vertex의 각 Edge를 보관하는 vector
vector<int> level; // vertex의 level 보관
vector<int> iter; // 각 vertex의 Edge 방문개수 보관

int n, m;
vector<vector<char>> arr;

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

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < arr.size(); i++)
			arr[i].clear();
		arr.clear();
		arr.resize(n, vector<char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) 
				cin >> arr[i][j];
			
		v = n * m + 2;
		for (int i = 0; i < graph.size(); i++)
			graph[i].clear();
		graph.resize(v);
		level.resize(v);
		iter.resize(v);

		int source = 0;
		int sink = v - 1;
		
		int cnt = 0;
		int dy[] = { 0, 0, 1, 1, -1, -1 };
		int dx[] = { -1, 1, -1, 1, -1, 1 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int hereIdx = i * m + j + 1;

				if (arr[i][j] == 'x') {
					cnt++;
					continue;
				}
				
				if (j % 2) {
					graph[0].emplace_back(hereIdx, 1, graph[hereIdx].size());
					graph[hereIdx].emplace_back(0, 0, graph[0].size() - 1);
					for (int k = 0; k < 6; k++) {
						int nextY = i + dy[k];
						int nextX = j + dx[k];
						int nextIdx = nextY * m + nextX + 1;

						if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
							continue;
						if (arr[nextY][nextX] == 'x')
							continue;
						graph[hereIdx].emplace_back(nextIdx, 1, graph[nextIdx].size());
						graph[nextIdx].emplace_back(hereIdx, 0, graph[hereIdx].size() - 1);
					}
				}
				else {
					graph[hereIdx].emplace_back(sink, 1, graph[sink].size());
					graph[sink].emplace_back(hereIdx, 0, graph[hereIdx].size() - 1);
				}
			}
		}


		cout << n * m - cnt - maxFlow(source, sink) << endl;
	}
	
	return 0;
}
