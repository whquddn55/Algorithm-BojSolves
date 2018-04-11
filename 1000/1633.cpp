#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 1005

vector<int> graph[MAX_V];
int capacity[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int prv[MAX_V];

void spfa(int start) {
	memset(prv, -1, sizeof(prv));
	int dist[MAX_V];
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

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
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

int mcmf(int source, int sink) {
	int ans = 0;
	while (true) {
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
	return ans;
}

void addEdge(int from, int to, int cap, int co) {
	graph[from].push_back(to);
	graph[to].push_back(from);

	capacity[from][to] = cap;
	cost[from][to] = co;
	cost[to][from] = -co;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + 1000;
	int sink = rightStart + 2;

	for (int left = 0; left < 1000; left++)
		addEdge(source, leftStart + left, 1, 0);

	int a, b, left = 0;
	while (cin >> a >> b) {
		addEdge(leftStart + left, rightStart + 0, 1, -a);
		addEdge(leftStart + left, rightStart + 1, 1, -b);
		left++;
	}
	addEdge(rightStart + 0, sink, 15, 0);
	addEdge(rightStart + 1, sink ,15, 0);

	cout << -mcmf(source, sink) << endl;

	return 0;
}
