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

#define MAX_N 1000

int n, m;
int a, b, k, g;
pii arr[MAX_N];

int dist[MAX_N];
vector<pii> adj[MAX_N];

void spfa() {
	fill_n(dist, MAX_N, INF);
	bool inQ[MAX_N] = { false, };
	queue<int> q;
	q.emplace(a);
	dist[a] = k;
	inQ[a] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		inQ[here] = false;

		for (auto e : adj[here]) {
			int next = e.first;
			int nextCost = e.second + dist[here];
			int idx = lower_bound(arr, arr + g, dist[here], [](pii& a, int b)-> bool {
				return a.second < b;
			}) - arr;
			if ((arr[idx - 1].first == here && arr[idx].first == next) || (arr[idx - 1].first == next && arr[idx].first == here))
				nextCost = arr[idx].second + e.second;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				if (!inQ[next]) {
					q.emplace(next);
					inQ[next] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	cin >> a >> b >> k >> g;
	a--;
	b--;
	for (int i = 0; i < g; i++) {
		cin >> arr[i].first;
		arr[i].first--;
	}
	
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	for (int i = 0; i < g - 1; i++) {
		for (auto e : adj[arr[i].first]) {
			if (e.first == arr[i + 1].first) {
				arr[i + 1].second = e.second;
				break;
			}
		}
	}
	for (int i = 1; i < g; i++)
		arr[i].second += arr[i - 1].second;

	spfa();
	cout << dist[b] - k<< endl;

	return 0;
}