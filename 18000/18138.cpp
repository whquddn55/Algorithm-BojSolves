#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)


#define MAX_V 405

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

int n, m;
int w1[MAX_V / 2];
int w2[MAX_V / 2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> w1[i];
    for (int i = 0; i < m; ++i)
        cin >> w2[i];

    int source = n + m;
    int sink = n + m + 1;

    for (int i = 0; i < n; ++i)
        addEdge(source, i, 1);
    for (int i = n; i < n + m; ++i)
        addEdge(i, sink, 1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if ((w1[i] <= 2 * w2[j] && w1[i] * 3 >= 4 * w2[j]) ||
                (w1[i] <= w2[j] && w1[i] * 5 >= 4 * w2[j]))
                addEdge(i, n + j, 1);
        }


	cout << maxFlow(source, sink) << endl; // source에서 sink로의 maximalFlow 구함

    /*	주의사항
    1. 굳이 vertex 개수를 타이트하게 맞춰줄 필요 없다!
    2. vertex번호 설정을 철저히해서 햇갈리는 일이 없도록 하자! ( source, sink설정이나 leftStart, rightStart같은.. )
    3. graph에 Edge추가하는 작업이 상당히 햇갈리니 유의하자!
    */

	return 0;
}
