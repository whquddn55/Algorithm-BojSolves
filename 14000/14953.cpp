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

#define MAX_N 100000

int n, m;
vector<int> adj[MAX_N];

queue<int> q;
int dist[MAX_N];

int ans = 1;

void bfs() {
	for (int i = 0; i < n; i++) {
		q.emplace(i);
		dist[i] = 1;
	}

	while (q.size()) {
		int here = q.front();
		q.pop();

		for (auto& next : adj[here]) {
			if (adj[next].size() > adj[here].size() && dist[next] < dist[here] + 1) {
				q.emplace(next);
				dist[next] = dist[here] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	bfs();

	for (int i = 0; i < n; i++)
		ans = max(ans, dist[i]);
	cout << ans << endl;

	return 0;
}