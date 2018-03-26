#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, reverse;
	bool c;
	Edge(int to, int capacity, int reverse, bool c)
		:to(to), capacity(capacity), reverse(reverse), c(c) {}
};

int v; // graph의 총 vertex 개수
vector<vector<Edge>> graph; // vertex의 각 Edge를 보관하는 vector
vector<int> level; // vertex의 level 보관
vector<int> iter; // 각 vertex의 Edge 방문개수 보관

int r, c;
vector<vector<char>> arr;
vector<pii> carPos;
vector<pii> lotPos;
vector<vector<int>> dist;

void bfs(int s, int mid) {
	fill(level.begin(), level.end(), -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (Edge& e : graph[v]) {
			if (e.capacity > 0 && level[e.to] < 0 && dist[v][e.to] <= mid) {
				level[e.to] = level[v] + 1;
				q.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f, int mid) {
	if (v == t)
		return f;
	for (int& i = iter[v]; i < graph[v].size(); i++) {
		Edge& e = graph[v][i];
		if (e.capacity > 0 && level[v] < level[e.to] && dist[v][e.to] <= mid) {
			int d = dfs(e.to, t, min(f, e.capacity), mid);
			if (d > 0) {
				e.capacity -= d;
				graph[e.to][e.reverse].capacity += d;
				return d;
			}
		}
	}

	return 0;
}

int maxFlow(int s, int t, int mid) {
	int flow = 0;
	while (true) {
		bfs(s, mid);
		if (level[t] < 0)
			return flow;
		fill(iter.begin(), iter.end(), 0);
		int f;
		while ((f = dfs(s, t, INF, mid)) > 0)
			flow += f;
	}
	return flow;
}

void getDist(int carIndex) {
	queue<pair<pii, int>> q;
	q.emplace(make_pair(carPos[carIndex].first, carPos[carIndex].second), 0);
	vector<vector<bool>> visited(r, vector<bool>(c));
	visited[carPos[carIndex].first][carPos[carIndex].second] = true;

	while (!q.empty()) {
		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		int dy[] = { 0, -1, 1, 0 };
		int dx[] = { -1, 0, 0, 1 };
		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= r || nextY < 0 || nextX >= c || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (arr[nextY][nextX] == 'X')
				continue;
			if (arr[nextY][nextX] == 'P') {
				int lotIndex = lower_bound(lotPos.begin(), lotPos.end(), make_pair(nextY, nextX)) - lotPos.begin();
				dist[carIndex + 1][lotIndex + carPos.size() + 1] = dist[lotIndex + carPos.size() + 1][carIndex + 1] = cost + 1;
			}

			q.emplace(make_pair(nextY, nextX), cost + 1);
			visited[nextY][nextX] = true;
		}
	}
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;
	while (left <= right) {
		int mid = (left + right) / 2;
		for (int i = 0; i < v; i++)
			for (int j = 0; j < graph[i].size(); j++)
				graph[i][j].capacity = graph[i][j].c;
#ifdef DEBUG
		cout << left << ", " << right << ", " << mid << ", " << maxFlow(0, v - 1, mid) << endl;
		for (int i = 0; i < v; i++)
			for (int j = 0; j < graph[i].size(); j++)
				graph[i][j].capacity = graph[i][j].c;
#endif
		if (maxFlow(0, v - 1, mid) >= carPos.size())
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> c;
	arr.resize(r, vector<char>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C')
				carPos.emplace_back(i, j);
			else if (arr[i][j] == 'P')
				lotPos.emplace_back(i, j);
		}

	if (carPos.size() > lotPos.size()) {
		cout << -1 << endl;
		return 0;
	}

	v = carPos.size() + lotPos.size() + 2; // vertex 개수 설정
	graph.resize(v); // graph의 크기를 vertex개수만큼
	level.resize(v); // level의 크기를 vertex개수만큼
	iter.resize(v); // iter의 크기를 vertex개수만큼

	int source = 0; // source의 vertex 번호
	int leftStart = 1;
	int rightStart = leftStart + carPos.size();
	int sink = v - 1; // sink의 vertex 번호

	for (int left = 0; left < carPos.size(); left++) {
		graph[source].emplace_back(leftStart + left, 1, graph[leftStart + left].size(), true);
		graph[leftStart + left].emplace_back(source, 0, graph[source].size() - 1, false);
	}
	for (int left = 0; left < carPos.size(); left++)
		for (int right = 0; right < lotPos.size(); right++) {
			graph[leftStart + left].emplace_back(rightStart + right, 1, graph[rightStart + right].size(), true);
			graph[rightStart + right].emplace_back(leftStart + left, 0, graph[leftStart + left].size() - 1, false);
		}
	for (int right = 0; right < lotPos.size(); right++) {
		graph[rightStart + right].emplace_back(sink, 1, graph[sink].size(), true);
		graph[sink].emplace_back(rightStart + right, 0, graph[rightStart + right].size() - 1, false);
	}

	dist.resize(v, vector<int>(v, INF / 2));
	for (int i = 0; i < carPos.size(); i++)
		getDist(i);
	for (int i = 0; i < carPos.size(); i++)
		dist[source][leftStart + i] = dist[leftStart + i][source] = 0;
	for (int i = 0; i < lotPos.size(); i++)
		dist[rightStart + i][sink] = dist[sink][rightStart + i] = 0;

#ifdef DEBUG
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < graph[i].size(); j++)
			if (graph[i][j].capacity)
				cout << i << " to " << graph[i][j].to << " : " << dist[i][graph[i][j].to] << endl;
	}
#endif

	int ans = binarySearch(0, INF / 3);

	cout << (ans >= INF / 3 ? -1 : ans) << endl;

	return 0;
}
