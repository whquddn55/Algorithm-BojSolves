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

#define MAX_N 1005

vector<pii> adj[MAX_N];
int dist[MAX_N];

int n, e;

void dijkstra(int start) {
	fill(dist, dist + MAX_N, INT_MAX / 2);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int here = pq.top().second;
		int hereWeight = pq.top().first;
		pq.pop();

		if (dist[here] < hereWeight)
			continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int next = adj[here][i].first;
			int nextWeight = hereWeight + adj[here][i].second;
			if (nextWeight < dist[next]) {
				dist[next] = nextWeight;
				pq.emplace(nextWeight, next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> e;
	while(e--){
		int from, to;
		int weight;
		cin >> from >> to >> weight;
		from--; to--;
		adj[from].emplace_back(to, weight);
	}
	int from, to;
	cin >> from >> to;
	from--; to--;
	dijkstra(from);
	cout << dist[to] << endl;
	
	return 0;
}