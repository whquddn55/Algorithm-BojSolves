#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, d, c;

vector<vector<pii>> adj;
vector<int> dist;
vector<bool> inQ;
vector<int> cycle;

void spfa(int start) {
	dist[start] = 0;
	inQ[start] = true;
	cycle[start]++;
	queue<int> q;
	q.emplace(start);
	
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int cost = adj[here][i].second;

			if (dist[next] > dist[here] + cost) {
				dist[next] = dist[here] + cost;

				if (!inQ[next]) {
					cycle[next]++;

					q.emplace(next);
					inQ[next] = true;
				}
			}

			if (cycle[next] >= n) {
				cout << -1 << endl;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> d >> c;
		for (int i = 0; i < adj.size(); i++)
			adj[i].clear();
		adj.clear();
		dist.clear();
		inQ.clear();
		cycle.clear();
		adj.resize(n + 1);
		dist.resize(n + 1, INF);
		inQ.resize(n + 1, false);
		cycle.resize(n + 1, 0);

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].emplace_back(a, s);
		}
		
		spfa(c);

		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++)
			if (dist[i] != INF) {
				ans1++;
				ans2 = max(ans2, dist[i]);
			}

		cout << ans1 << ' ' << ans2 << endl;
	}

	return 0;
}
