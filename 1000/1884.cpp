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

#define MAX_N 100
#define MAX_K 10001

int k, n, r;
vector<pair<int, pii>> adj[MAX_N];

void dijkstra() {
	priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
	pq.emplace(pii(0, 0), 0);

	while (!pq.empty()) {
		int here = pq.top().second;
		int len = pq.top().first.first;
		int cost = pq.top().first.second;
		pq.pop();

		if (here == n - 1) {
			cout << len << endl;
			return;
		}

		for (auto e : adj[here]) {
			int next = e.first;
			int nextLen = len + e.second.first;
			int nextCost = cost + e.second.second;

			if (nextCost > k)
				continue;

			pq.emplace(pii(nextLen, nextCost), next);
		}
	}
	cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> k >> n >> r;
	while (r--) {
		int u, v, l, t;
		cin >> u >> v >> l >> t;
		u--;
		v--;
		adj[u].emplace_back(v, pii(l, t));
	}

	dijkstra();

	return 0;
}