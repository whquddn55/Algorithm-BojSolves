#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 2002

int v;

vector<int> adj[MAX_V];
int capacity[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int prv[MAX_V];
int dist[MAX_V];

int vertex, edge;

void spfa(int start) {
	memset(prv, -1, MAX_V * sizeof(int));
	fill(dist, dist + MAX_V, INF);
	bool inQ[MAX_V] = { false, };
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	inQ[start] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if (capacity[here][next] - flow[here][next] > 0 && dist[next] > dist[here] + cost[here][next]) {
				dist[next] = dist[here] + cost[here][next];
				prv[next] = here;

				if (!inQ[next]) {
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> vertex) {
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		memset(&capacity[0][0], 0, MAX_V * MAX_V * sizeof(int));
		memset(&cost[0][0], 0, MAX_V * MAX_V * sizeof(int));
		memset(&flow[0][0], 0, MAX_V * MAX_V * sizeof(int));

		cin >> edge;
		v = vertex * 2 + 2;
		int source = 0;
		int sink = v - 1;

		capacity[source][1] = 2;

		adj[source].push_back(1);
		adj[1].push_back(source);

		capacity[sink - 1][sink] = 2;

		adj[sink - 1].push_back(sink);
		adj[sink].push_back(sink - 1);

		for (int i = 1; i <= vertex; i++) {
			capacity[i][i + vertex] = 1;

			adj[i].push_back(i + vertex);
			adj[i + vertex].push_back(i);
		}

		capacity[1][1 + vertex] = 2;
		capacity[vertex][vertex + vertex] = 2;

		for (int i = 0; i < edge; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			capacity[a + vertex][b] = 1;

			adj[a + vertex].push_back(b);
			adj[b].push_back(a + vertex);

			cost[a + vertex][b] = c;
			cost[b][a + vertex] = -c;
		}

		int ans = 0;
		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			spfa(source);

			if (prv[sink] == -1)
				break;
			int maxFlow = INF;
			for (int i = sink; i != source; i = prv[i])
				maxFlow = min(maxFlow, capacity[prv[i]][i] - flow[prv[i]][i]);

			for (int i = sink; i != source; i = prv[i]) {
				ans += maxFlow * cost[prv[i]][i];
				flow[prv[i]][i] += maxFlow;
				flow[i][prv[i]] -= maxFlow;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
