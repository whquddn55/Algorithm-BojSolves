#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 505

vector<pii> adj[MAX_N];
ll dist[MAX_N];

int n, e;

void spfa() {
	queue<int> q;
	vector<bool> inQ(n, false);
	vector<int> cycle(n, 0);

	q.push(0);
	dist[0] = 0;
	inQ[0] = true;

	cycle[0]++;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < adj[here].size(); ++i) {
			int next = adj[here][i].first;
			int cost = adj[here][i].second;

			if (dist[next] > dist[here] + cost) {
				dist[next] = dist[here] + cost;
				if (!inQ[next]) {
					cycle[next]++;
					q.push(next);
					inQ[next] = true;
					if (cycle[next] == n) {
						cout << -1 << endl;
						exit(0);
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fill(dist, dist + MAX_N, INF);

	cin >> n >> e;
	while(e--){
		int from, to;
		int weight;
		cin >> from >> to >> weight;
		from--; to--;
		adj[from].emplace_back(to, weight);
	}
	spfa();

	for (int i = 1; i < n; ++i) {
		if (dist[i] == INF)
			dist[i] = -1;
		cout << dist[i] << endl;
	}
	
	return 0;
}