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

#define MAX_V 6005
#define MAX_N 1000

struct Edge {
	int to, capacity, reverse, cost, flow;
	Edge(int to, int capacity, int cost, int reverse)
		:to(to), capacity(capacity), cost(cost), reverse(reverse), flow(0) {}
};

vector<Edge> graph[MAX_V];
int prv[MAX_V];
int edgeIdx[MAX_V];

int n, k;
int arr[MAX_N][3];


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
	while (spfa(source, sink) && cnt < k) {
		cnt++;
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

	cin >> n >> k;

	int source = 0;
	int leftStart = 1;
	int rightStart = leftStart + 3 * n;
	int sink = rightStart + 3 * n;

	int lcnt = 0, rcnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) {
			int t;
			cin >> t;
			if ((i + j) % 2) {
				addEdge(source, leftStart + lcnt, 1, -t);
				arr[i][j] = lcnt;
				lcnt++;
			}
			else {
				addEdge(rightStart + rcnt, sink, 1, -t);
				arr[i][j] = rcnt;
				rcnt++;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) {
			if ((i + j) % 2) {
				int dy[] = { 0, -1, 0, 1 };
				int dx[] = { -1, 0, 1, 0 };
				for (int k = 0; k < 4; k++) {
					int nextY = i + dy[k];
					int nextX = j + dx[k];
					if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= 3)
						continue;

					addEdge(leftStart + arr[i][j], rightStart + arr[nextY][nextX], 1, 0);
				}
			}
		}

	cout << -mcmf(source, sink) << endl;


	return 0;
}
