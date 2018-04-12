#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 1005

struct Edge {
	int to, capacity, reverse, cost, flow;
	Edge(int to, int capacity, int cost, int reverse)
		:to(to), capacity(capacity), cost(cost), reverse(reverse), flow(0){}
};

int n, a, b;

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

int mcmf(int source, int sink) {
	memset(prv, -1, sizeof(prv));
	memset(edgeIdx, -1, sizeof(edgeIdx));
	int ans = 0;
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
			ans += maxFlow * graph[prev][idx].cost;
			graph[prev][idx].flow += maxFlow;
			graph[i][graph[prev][idx].reverse].flow -= maxFlow;
		}
	}
	return ans;
}

void addEdge(int from, int to, int capacity, int cost) {
	graph[from].emplace_back(to, capacity, cost, graph[to].size());
	graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
		cin >> n >> a >> b;
		if (n == 0)
			break;

		int source = 0;
		int leftStart = 1;
		int rightStart = leftStart + 2;
		int sink = rightStart + n;

		for (int i = 0; i < MAX_V; i++)
			graph[i].clear();


		addEdge(source, leftStart + 0, a, 0);
		addEdge(source, leftStart + 1, b, 0);

		for (int right = 0; right < n; right++) {
			int k, da, db;
			cin >> k >> da >> db;

			addEdge(leftStart + 0, rightStart + right, INF, da);
			addEdge(leftStart + 1, rightStart + right, INF, db);
			addEdge(rightStart + right, sink, k, 0);
		}

		cout << mcmf(source, sink) << endl;
	}


	return 0;
}
