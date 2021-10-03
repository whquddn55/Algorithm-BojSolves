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
#define MAX_N 500005
#define MOD 1000000007

#define MAX_V 405

struct Edge {
	int to, capacity, reverse, cost, flow;
	Edge(int to, int capacity, int cost, int reverse)
		:to(to), capacity(capacity), cost(cost), reverse(reverse), flow(0){}
};

int n, m;

vector<Edge> graph[MAX_V];
int prv[MAX_V];
int edgeIdx[MAX_V];

bool spfa(int source, int sink) {
	ll dist[MAX_V];
	bool inQ[MAX_V] = { false, };
	queue<int> q;
	fill(dist, dist + MAX_V, LLONG_MAX);
	dist[source] = 0;
	inQ[source] = true;
	q.push(source);

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].to;
			int capacity = graph[here][i].capacity;
			int flow = graph[here][i].flow;
			int cost = graph[here][i].cost;
			if (capacity - flow > 0 && dist[next] > dist[here] + cost) {
				dist[next] = dist[here] + cost;
				prv[next] = here;
				edgeIdx[next] = i;

				if (!inQ[next]) {
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}

	return dist[sink] != LLONG_MAX;
}

pll mcmf(int source, int sink) {
	memset(prv, -1, sizeof(prv));
	memset(edgeIdx, -1, sizeof(edgeIdx));
	ll ans = 0;
	int flow = 0;
	while (spfa(source, sink)) {
		int maxFlow = INF;
		for (int i = sink; i != source; i = prv[i]) {
			int prev = prv[i];
			int idx = edgeIdx[i];
			maxFlow = min(maxFlow, graph[prev][idx].capacity - graph[prev][idx].flow);
		}
		for (int i = sink; i != source; i = prv[i]) {
			int prev = prv[i];
			int idx = edgeIdx[i];
			ans += (ll)maxFlow * graph[prev][idx].cost;
			graph[prev][idx].flow += maxFlow;
			graph[i][graph[prev][idx].reverse].flow -= maxFlow;
		}
		flow += maxFlow;
	}
	return {flow, ans};
}

void addEdge(int from, int to, int capacity, int cost) {
	graph[from].emplace_back(to, capacity, cost, graph[to].size());
	graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + n;
	int sink = rightStart + n;

	for (int i = 0; i < n; ++i)
		addEdge(source, leftStart + i, 1, 0);

	
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		addEdge(leftStart + a, rightStart + b, 1, c);
	}

	for (int i = 0; i < n; ++i)
		addEdge(rightStart + i, sink, 1, 0);

	pll ans = mcmf(source, sink);
	if (ans.first < n)
		cout << 0 << endl;
	else {
		cout << 1 << endl;
		cout << ans.second << endl;
		for (int i = 0; i < n; ++i)
			for (auto e : graph[leftStart + i])
				if (e.flow == 1)
					cout << i + 1 << ' ' << e.to - n << endl;
	}


	return 0;
}
