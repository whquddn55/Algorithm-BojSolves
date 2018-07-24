#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (LLONG_MAX / 2)

#define MAX_N 201

int n, m;
int from, to;
vector<pii> adj[MAX_N]; // 인접리스트 [from].emplace_back(to, cost)
ll dist[MAX_N]; // start에서의 거리(start는 0임)

bool bfs() {
	queue<int> q;
	q.emplace(from * 2);
	bool visited[MAX_N] = { false, };
	visited[from * 2] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (here == to * 2 + 1)
			return true;

		for (auto e : adj[here]) {
			if (visited[e.first])
				continue;

			q.emplace(e.first);
			visited[e.first] = true;
		}
	}
	return false;
}

bool cycleBfs(vector<int>& cycleNode, int to) {
	queue<int> q;
	bool visited[MAX_N * 2] = { false, };
	for (auto e : cycleNode) {
		q.push(e);
		visited[e] = true;
		if (e == to)
			return true;
	}

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (auto e : adj[here]) {
			int next = e.first;

			if (visited[next])
				continue;
			if (to == next)
				return true;

			q.push(next);
			visited[next] = true;
		}
	}
	return false;
}

void spfa(int start) {
	fill(dist, dist + n * 2, INF);
	bool inQ[MAX_N] = { false, };
	int cycle[MAX_N] = { 0, };
	queue<int> q;
	q.emplace(start);

	dist[start] = 0;
	inQ[start] = true;
	cycle[start]++;

	vector<int> cycleNode;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int cost = adj[here][i].second;

			if (dist[next] > dist[here] + cost && dist[next] != -INF) {
				dist[next] = dist[here] + cost;
				if (cycle[next] >= n * 2) {
					cycleNode.push_back(next);
					continue;
				}
				if (!inQ[next]) {
					cycle[next]++;
					q.emplace(next);
					inQ[next] = true;
				}
			}
		}
	}

	if (cycleBfs(cycleNode, to * 2 + 1)) {
		cout << "Gee" << endl;
		return;
	}

	cout << -dist[to * 2 + 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> from >> to >> m;

	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u * 2 + 1].emplace_back(v * 2, cost);
	}

	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		adj[i * 2].emplace_back(i * 2 + 1, -value);
	}

	if (!bfs()) {
		cout << "gg" << endl;
		return 0;
	}

	spfa(from * 2);

	return 0;
}
