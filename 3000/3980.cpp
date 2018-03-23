#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int v;

vector<vector<int>> adj;
vector<vector<int>> capacity;
vector<vector<int>> cost;
vector<vector<int>> flow;

vector<int> prev;
vector<int> dist;

int abillity[11][11];

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

	int tc;
	cin >> tc;

	while (tc--) {
		v = 11 + 11 + 2;
		int source = 0;
		int sink = v - 1;
		int leftStart = 1;
		int rightStart = 11 + 1;

		for (int i = 0; i < capacity.size(); i++) {
			capacity[i].clear();
			cost[i].clear();
			flow[i].clear();
			adj[i].clear();
		}
		capacity.clear();
		cost.clear();
		flow.clear();
		::prev.clear();
		dist.clear();
		adj.clear();

		capacity.resize(v, vector<int>(v, 0));
		cost.resize(v, vector<int>(v, 0));
		flow.resize(v, vector<int>(v, 0));
		::prev.resize(v);
		dist.resize(v);
		adj.resize(v);

		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> abillity[i][j];

		for (int left = 0; left < 11; left++) {
			capacity[source][leftStart + left] = 1;

			adj[source].push_back(leftStart + left);
			adj[leftStart + left].push_back(source);
		}

		for (int right = 0; right < 11; right++) {
			capacity[rightStart + right][sink] = 1;

			adj[rightStart + right].push_back(sink);
			adj[sink].push_back(rightStart + right);
		}
		
		for (int left = 0; left < 11; left++) {
			for (int right = 0; right < 11; right++) {
				if (abillity[left][right]) {
					capacity[leftStart + left][rightStart + right] = 1;

					adj[leftStart + left].push_back(rightStart + right);
					adj[rightStart + right].push_back(leftStart + left);

					cost[leftStart + left][rightStart + right] = -abillity[left][right];
					cost[rightStart + right][leftStart + left] = abillity[left][right];
				}
			}
		}

		int ans = 0;
		while (true) {
			spfa(source);

			if (::prev[sink] == -1)
				break;

			int maxFlow = INF;
			for (int i = sink; i != source; i = ::prev[i])
				maxFlow = min(maxFlow, capacity[::prev[i]][i] - flow[::prev[i]][i]);

			for (int i = sink; i != source; i = ::prev[i]) {
				ans += maxFlow * cost[::prev[i]][i];
				flow[::prev[i]][i] += maxFlow;
				flow[i][::prev[i]] -= maxFlow;
			}
		}
		cout << -ans << endl;
	}

	return 0;
}
