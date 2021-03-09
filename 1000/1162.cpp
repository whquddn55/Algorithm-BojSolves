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

#define MAX_N 10005
#define MOD 1000000007

int n, m, k;
vector<pii> adj[MAX_N];

ll dijkstra() {
	priority_queue< pair<pll, int>, vector< pair<pll, int> >, greater< pair<pll, int> > > pq;
	ll dist[MAX_N][21];
	for (int i = 0; i < MAX_N; ++i)
		fill(dist[i], dist[i] + 21, LLONG_MAX);
	pq.emplace(pll(0, 0), 0);
	dist[0][0] = 0;

	while (pq.size()) {
		int here = pq.top().second;
		ll hereCost = pq.top().first.first;
		ll hereCnt = pq.top().first.second;
		pq.pop();

		if (dist[here][hereCnt] < hereCost)
			continue;

		for (auto nextPair : adj[here]) {
			int next = nextPair.first;
			ll nextCost = hereCost + nextPair.second;
			int nextCnt = hereCnt + 1;

			if (dist[next][hereCnt] > nextCost) {
				pq.emplace(pll(nextCost, hereCnt), next);
				dist[next][hereCnt] = nextCost;
			}
			if (nextCnt <= k) {
				if (dist[next][nextCnt] > hereCost) {
					pq.emplace(pll(hereCost, nextCnt), next);
					dist[next][nextCnt] = hereCost;
				}
			}
		}
	}
	ll result = LLONG_MAX;
	for (int i = 0; i < 21; ++i)
		result = min(result, dist[n - 1][i]);
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> n >> m >> k;
	while (m--) {
		int f, t, d;
		cin >> f >> t >> d;
		f--;
		t--;
		adj[f].emplace_back(t, d);
		adj[t].emplace_back(f, d);
	}

	cout << dijkstra() << endl;
	
	
	return 0;
}