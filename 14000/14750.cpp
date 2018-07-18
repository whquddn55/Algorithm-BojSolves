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

#define INF (INT_MAX / 2)

#define MAX_V 305
#define MAX_N 1000

struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
	int to, capacity, flow, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), flow(0), reverse(reverse) {}
};

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

int n, k, h, m;
pair<pii, pii> line[MAX_N];
pii hole[MAX_V];
pii mouse[MAX_V];

int ccw(pii a, pii b, pii c) {
	ll value = (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
	if (value == 0)
		return 0; // 일직선
	return value > 0 ? 1 : -1; // 1 : 반 시계 방향 -1 : 시계 방향
}

bool isAcross(const pair<pii, pii>& l1, const pair<pii, pii>& l2) {
	int v1 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
	int v2 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);
	
	pii on;
	if (v1 == 0)
		if (ccw(l1.first, l1.second, l2.first) == 0)
			on = l2.first;
		else
			on = l2.second;

	if ( (v1 == -1 && v2 == -1) || ( v1 == 0 && (on.first <= max(l1.first.first, l1.second.first) && on.first >= min(l1.first.first, l1.second.first)) && (on.second <= max(l1.first.second, l1.second.second) && on.second >= min(l1.first.second, l1.second.second)) && (on != l1.second) ) )
		return true;
	else
		return false;
}

bool isDirect(const pii& mouse, const pii& hole) {
	pair<pii, pii> l = { mouse, hole };
	for (int i = 0; i < n; i++)
		if (isAcross(l, line[i]))
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k >> h >> m;

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + m;
	int sink = rightStart + h;

	pii prv;
	cin >> prv;
	for (int i = 1; i < n; i++) {
		pii t;
		cin >> t;
		line[i - 1] = { prv, t };
		prv = t;
	}
	line[n - 1] = { line[n - 2].second, line[0].first };

	for (int i = 0; i < h; i++)
		cin >> hole[i];

	for (int i = 0; i < m; i++)
		cin >> mouse[i];

	for (int i = 0; i < m; i++)
		addEdge(source, leftStart + i, 1);

	for (int i = 0; i < h; i++)
		addEdge(rightStart + i, sink, k);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < h; j++) 
			if (isDirect(mouse[i], hole[j])) 
				addEdge(leftStart + i, rightStart + j, 1);

	cout << (maxFlow(source, sink) == m ? "Possible" : "Impossible") << endl;

	return 0;
}
