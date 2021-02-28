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

#define MAX_N 20005
#define MOD 1000000007

int v, e;
vector<pii> adj[MAX_N];


void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	int dist[MAX_N];

	fill(dist, dist + MAX_N, INF);
	q.emplace(0, start);
	dist[start] = 0;
	while (q.size()) {
		int here = q.top().second;
		int hereDist = q.top().first;
		q.pop();

		if (hereDist > dist[here])
			continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int next = adj[here][i].first;
			int nextDist = adj[here][i].second + dist[here];

			if (nextDist < dist[next]) {
				dist[next] = nextDist;
				q.emplace(dist[next], next);
			}
		}
	}

	for (int i = 0; i < v; ++i)
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> v >> e;
	int start;
	cin >> start;
	start--;
	while (e--) {
		int f, t, dist;
		cin >> f >> t >> dist;
		f--;
		t--;
		adj[f].emplace_back(t, dist);
	}

	dijkstra(start);

	return 0;
}