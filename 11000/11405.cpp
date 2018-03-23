#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, m;
int v;

vector<vector<int>> adj;
vector<vector<int>> capacity;
vector<vector<int>> cost;
vector<vector<int>> flow;

vector<int> prev;
vector<int> dist;

vector<int> arr1, arr2;
vector<vector<int>> arr3;

void spfa(int start) {
	fill(::prev.begin(), ::prev.end(), -1);
	fill(dist.begin(), dist.end(), INF);
	vector<bool> inQ(v, false);
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
				::prev[next] = here;

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

	cin >> n >> m;
	v = n + m + 2;
	int source = 0;
	int sink = v - 1;
	int leftStart = 1;
	int rightStart = m + 1;

	capacity.resize(v, vector<int>(v, 0));
	cost.resize(v, vector<int>(v, 0));
	flow.resize(v, vector<int>(v, 0));
	::prev.resize(v);
	dist.resize(v);
	adj.resize(v);

	arr1.resize(n);
	arr2.resize(m);
	arr3.resize(m, vector<int>(n));

	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr3[i][j];

	for (int left = 0; left < m; left++) {
		capacity[source][leftStart + left] = arr2[left];

		adj[source].push_back(leftStart + left);
		adj[leftStart + left].push_back(source);
	}

	for (int left = 0; left < m; left++) {
		for (int right = 0; right < n; right++) {
			capacity[leftStart + left][rightStart + right] = arr2[left];

			adj[leftStart + left].push_back(rightStart + right);
			adj[rightStart + right].push_back(leftStart + left);

			cost[leftStart + left][rightStart + right] = arr3[left][right];
			cost[rightStart + right][leftStart + left] = -arr3[left][right];
		}
	}

	for (int right = 0; right < n; right++) {
		capacity[rightStart + right][sink] = arr1[right];

		adj[rightStart + right].push_back(sink);
		adj[sink].push_back(rightStart + right);
	}

	int result = 0;
	while (true) {
		spfa(source);

		if (::prev[sink] == -1)
			break;

		int maxFlow = INF;
		for (int i = sink; i != source; i = ::prev[i])
			maxFlow = min(maxFlow, capacity[::prev[i]][i] - flow[::prev[i]][i]);

		for (int i = sink; i != source; i = ::prev[i]) {
			result += maxFlow * cost[::prev[i]][i];
			flow[::prev[i]][i] += maxFlow;
			flow[i][::prev[i]] -= maxFlow;
		}
	}
	cout << result << endl;

	return 0;
}
