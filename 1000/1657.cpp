#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 15
#define MAX_V MAX_SIZE * MAX_SIZE + 3

struct Edge {
	int to, capacity, reverse, cost, flow;
	Edge(int to, int capacity, int cost, int reverse)
		:to(to), capacity(capacity), cost(cost), reverse(reverse), flow(0){}
};

int table[7][7] = { { 10, 8, 7, 5, 0, 1,},
					{ 8, 6, 4, 3, 0, 1,},
					{ 7, 4, 3, 2, 0, 1,},
					{ 5, 3, 2, 2, 0, 1,},
					{ 0, 0, 0, 0, 0, 0,},
					{ 1, 1, 1, 1, 0, 0,}, 
};
int n, m;
char arr[MAX_SIZE][MAX_SIZE];

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

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int source = n * m;
	int sink = source + 1;

	int dy[] = { 0, -1, 1, 0 };
	int dx[] = { -1, 0, 0, 1 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2) {
				addEdge(i * m + j, sink, 1, 0);
			}
			else {
				addEdge(source, i * m + j, 1, 0);
				addEdge(i * m + j, sink, 1, 0);
				for (int k = 0; k < 4; k++) {
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					if (nextY >= n || nextX >= m || nextY < 0 || nextX < 0)
						continue;

					addEdge(i * m + j, nextY * m + nextX, 1, -table[arr[i][j] - 'A'][arr[nextY][nextX] - 'A']);
				}
			}
		}

	cout << -mcmf(source, sink) << endl;


	return 0;
}
