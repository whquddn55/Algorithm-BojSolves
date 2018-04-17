#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 20 + 20 + 3

int n;

vector<int> graph[MAX_V];
int capacity[MAX_V][MAX_V];
double cost[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int prv[MAX_V];

void spfa(int start) {
	memset(prv, -1, sizeof(prv));
	double dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	bool inQ[MAX_V] = { false, };
	queue<int> q;
	q.push(start);
	dist[start] = 1.0;
	inQ[start] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (capacity[here][next] - flow[here][next] > 0 && dist[next] > dist[here] * cost[here][next]) {
				dist[next] = dist[here] * cost[here][next];
				prv[next] = here;

				if (!inQ[next]) {
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}
}

double mcmf(int source, int sink) {
	double ans = 1.0;
	while (true) {
		spfa(source);
		if (prv[sink] == -1)
			break;
		int maxFlow = INF;
		for (int i = sink; i != source; i = prv[i])
			maxFlow = min(maxFlow, capacity[prv[i]][i] - flow[prv[i]][i]);
		for (int i = sink; i != source; i = prv[i]) {
			ans *= maxFlow * cost[prv[i]][i];
			flow[prv[i]][i] += maxFlow;
			flow[i][prv[i]] -= maxFlow;
		}
	}
	return ans;
}

void addEdge(int from, int to, int cap, double co) {
	graph[from].push_back(to);
	graph[to].push_back(from);

	capacity[from][to] = cap;
	cost[from][to] = co;
	cost[to][from] = 1 / co;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << fixed;
	cout.precision(6);

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + 20;
	int sink = rightStart + 20;

	cin >> n;
	if (n == 1) {
		double a;
		cin >> a;
		cout << a << endl;
		return 0;
	}
	for (int left = 0; left < n; left++)
		for (int right = 0; right < n; right++) {
			double a;
			cin >> a;
			if (a == 0.0)
				continue;
			addEdge(leftStart + left, rightStart + right, 1, 1 / (a / 100));
		}

	for (int left = 0; left < n; left++)
		addEdge(source, leftStart + left, 1, 1.0);
	for (int right = 0; right < n; right++)
		addEdge(rightStart + right, sink, 1, 1.0);

	cout << 1 / mcmf(source, sink) * 100 << endl;


	return 0;
}
