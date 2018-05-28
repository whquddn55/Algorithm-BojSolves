#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 402

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
	int maxFlow = 0;
	int minCost = 0;
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
	return { minCost, maxFlow };
}

void addEdge(int from, int to, int capacity, int cost) {
	graph[from].emplace_back(to, capacity, cost, graph[to].size());
	graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < MAX_V; i++)
			graph[i].clear();
		arr1.clear();
		arr2.clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2, w;
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			if (x1 > x2)
				swap(x1, x2);
			arr1.emplace_back(y1, x1, x2, w);
		}
		for (int i = 0; i < m; i++) {
			int x1, y1, x2, y2, w;
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			if (y1 > y2)
				swap(y1, y2);
			arr2.emplace_back(x1, y1, y2, w);
		}

		int source = 0;
		int leftStart = source + 1;
		int rightStart = leftStart + n;
		int sink = rightStart + m;

		for (int left = 0; left < n; left++)
			addEdge(source, leftStart + left, 1, 0);
		for (int right = 0; right < m; right++)
			addEdge(rightStart + right, sink, 1, 0);

		for (int left = 0; left < n; left++) {
			for (int right = 0; right < m; right++) {
				if (arr1[left].a >= arr2[right].b1 && arr1[left].a <= arr2[right].b2 && arr2[right].a >= arr1[left].b1 && arr2[right].a <= arr1[left].b2)
					addEdge(leftStart + left, rightStart + right, 1, -arr1[left].w * arr2[right].w);
			}
		}

		pii ans = mcmf(source, sink);
		cout << ans.second << ' ' << -ans.first << endl;
	}


	return 0;
}
