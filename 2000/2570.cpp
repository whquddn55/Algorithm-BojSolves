#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 101
#define MAX_V 20005

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, flow, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), flow(0), reverse(reverse) {}
};

vector<Edge> graph[MAX_V]; // vertex의 각 Edge를 보관하는 vector
int level[MAX_V]; // vertex의 level 보관
int iter[MAX_V]; // 각 vertex의 Edge 방문개수 보관

int n, m;
bool arr[MAX_N][MAX_N];

int leftValues[MAX_N][MAX_N];
int rightValues[MAX_N][MAX_N];

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

void checkLeft() {
	bool checked = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (checked) {
			checked = false;
			cnt++;
		}

		int hereY = 0;
		int hereX = i;
		while (true) {
			if (hereY >= n || hereY < 0 || hereX >= n || hereX < 0)
				break;
			if (arr[hereY][hereX]) {
				leftValues[hereY][hereX] = cnt;
				checked = true;
			}
			else {
				if (checked)
					cnt++;
				checked = false;
			}
			hereY++;
			hereX++;
		}
	}
	for (int i = 1; i < n; i++) {
		if (checked) {
			checked = false;
			cnt++;
		}

		int hereY = i;
		int hereX = 0;
		while (true) {
			if (hereY >= n || hereY < 0 || hereX >= n || hereX < 0)
				break;
			if (arr[hereY][hereX]) {
				leftValues[hereY][hereX] = cnt;
				checked = true;
			}
			else {
				if (checked)
					cnt++;
				checked = false;
			}
			hereY++;
			hereX++;
		}
	}
}

void checkRight() {
	bool checked = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (checked) {
			checked = false;
			cnt++;
		}

		int hereY = i;
		int hereX = 0;
		while (true) {
			if (hereY >= n || hereY < 0 || hereX >= n || hereX < 0)
				break;
			if (arr[hereY][hereX]) {
				rightValues[hereY][hereX] = cnt;
				checked = true;
			}
			else {
				if (checked)
					cnt++;
				checked = false;
			}
			hereY--;
			hereX++;
		}
	}
	for (int i = 1; i < n; i++) {
		if (checked) {
			checked = false;
			cnt++;
		}

		int hereY = n - 1;
		int hereX = i;
		while (true) {
			if (hereY >= n || hereY < 0 || hereX >= n || hereX < 0)
				break;
			if (arr[hereY][hereX]) {
				rightValues[hereY][hereX] = cnt;
				checked = true;
			}
			else {
				if (checked)
					cnt++;
				checked = false;
			}
			hereY--;
			hereX++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		fill(arr[i], arr[i] + n, true);
	memset(leftValues, -1, sizeof(leftValues));
	memset(rightValues, -1, sizeof(rightValues));

	while (m--)  {
		int y, x;
		cin >> y >> x;
		y--; x--;
		arr[y][x] = false;
	}

	checkLeft();
	checkRight();

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + 10000;
	int sink = rightStart + 10000;

	for (int left = 0; left < 10000; left++)
		addEdge(source, leftStart + left, 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j])
				addEdge(leftStart + leftValues[i][j], rightStart + rightValues[i][j], 1);

	for (int right = 0; right < 10000; right++)
		addEdge(rightStart + right, sink, 1);


	cout << maxFlow(source, sink) << endl;
	

	return 0;
}
