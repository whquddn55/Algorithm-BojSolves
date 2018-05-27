#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 805

struct Edge {
	int to, capacity, reverse, cost, flow;
	Edge(int to, int capacity, int cost, int reverse)
		:to(to), capacity(capacity), cost(cost), reverse(reverse), flow(0) {}
};

struct Data {
	int a, b1, b2, w;
	Data(int a, int b1, int b2, int w)
		: a(a), b1(b1), b2(b2), w(w) { }
};

int n, m;
vector<Data> arr1;
vector<Data> arr2;

vector<Edge> graph[MAX_V];
int prv[MAX_V];
int edgeIdx[MAX_V];

bool spfa(int source, int sink) {
	int dist[MAX_V];
	bool inQ[MAX_V] = { false, };
	queue<int> q;
	fill(dist, dist + MAX_V, INF);
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

	return dist[sink] != INF;
}

pii mcmf(int source, int sink) {
	memset(prv, -1, sizeof(prv));
	memset(edgeIdx, -1, sizeof(edgeIdx));
	int minCost = 0, maxFlow = 0;
	while (spfa(source, sink)) {
		int flow = INF;
		for (int i = sink; i != source; i = prv[i]) {
			int prev = prv[i];
			int idx = edgeIdx[i];
			flow = min(flow, graph[prev][idx].capacity - graph[prev][idx].flow);
		}
		for (int i = sink; i != source; i = prv[i]) {
			int prev = prv[i];
			int idx = edgeIdx[i];
			minCost += flow * graph[prev][idx].cost;
			graph[prev][idx].flow += flow;
			graph[i][graph[prev][idx].reverse].flow -= flow;
		}
		maxFlow += flow;
	}
	return {minCost, maxFlow};
}

void addEdge(int from, int to, int capacity, int cost) {
	graph[from].emplace_back(to, capacity, cost, graph[to].size());
	graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	int source = 0;
	int leftStart = source + 1;
	int rightStart = leftStart + n;
	int sink = rightStart + m;

	for (int left = 0; left < n; left++) {
		addEdge(source, leftStart + left, 1, 0);
		int num;
		cin >> num;
		while (num--) {
			int right, cost;
			cin >> right >> cost;
			right--;
			addEdge(leftStart + left, rightStart + right, 1, -cost);
		}
	}

	for (int right = 0; right < m; right++)
		addEdge(rightStart + right, sink, 1, 0);

	pii ans = mcmf(source, sink);
	cout << ans.second << endl << -ans.first << endl;

	return 0;
}
