#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (LLONG_MAX)
#define endl '\n'

#define MAX_N 5001

ll n, m, s, e;
ll dist[MAX_N];
vector<pair<pair<ll, ll>, bool>> adj[MAX_N];

void dijkstra() {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[1] = 0;
	pq.emplace(0, 1);

	while (!pq.empty()) {
		ll hereDist = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (auto& next : adj[here]) {
			int there = next.first.first;
			ll thereDist = next.first.second;
			bool rush = next.second;

			ll hd = hereDist;
			ll td = hd + thereDist;
			if (td < 0)
				continue;
			if (rush) {
				if (e <= hd || s >= td) {
					if (td < dist[there]) {
						dist[there] = td;
						pq.emplace(dist[there], there);
					}
				}
				else {
					ll startTime, endTime, remain;
					if (hd >= s) {
						startTime = hd;
						remain = td - hd;
					}
					else {
						startTime = s;
						remain = td - s;
					}

					if (remain * 2 >= (e - startTime))
						endTime = e;
					else {
						endTime = td;
						endTime += (endTime - startTime);
					}

					if (td + (endTime - startTime) / 2 < dist[there]) {
						dist[there] = td + (endTime - startTime) / 2;
						pq.emplace(dist[there], there);
					}
				}
			}
			else {
				if (hereDist + thereDist < dist[there]) {
					dist[there] = hereDist + thereDist;
					pq.emplace(dist[there], there);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	fill(dist, dist + MAX_N, INF);
	cin >> n >> m >> s >> e;
	s *= 2;
	e *= 2;
	while (m--) {
		int a, b, l, t1, t2;
		cin >> a >> b >> l >> t1 >> t2;

		l *= 2;
		adj[a].emplace_back(make_pair(b, l), t1);
		adj[b].emplace_back(make_pair(a, l), t2);
	}

	dijkstra();
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dist[i]);

	cout << ans / 2;
	if (ans % 2)
		cout << ".5" << endl;

	return 0;
}
