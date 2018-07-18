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

#define MAX_V 605

struct Edge {
	int to, capacity, reverse, cost, flow;
	Edge(int to, int capacity, int cost, int reverse)
		:to(to), capacity(capacity), cost(cost), reverse(reverse), flow(0) {}
};

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
	int cnt = 0;
	while (spfa(source, sink)) {
		if (cnt++ == 2)
			break;
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

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < MAX_V; i++)
			graph[i].clear();

		cin >> n >> m;

		int source = 0;
		int leftStart = 1;
		int rightStart = leftStart + n;
		int sink = rightStart + n;

		for (int i = 0; i < n; i++) {
			addEdge(source, leftStart + i, 1, 0);
			addEdge(leftStart + i, rightStart + i, 1, -1);
			addEdge(rightStart + i, sink, 1, 0);
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			addEdge(rightStart + u, leftStart + v, 1, 0);
		}

		cout << -mcmf(source, sink) << endl;
	}


	return 0;
}
