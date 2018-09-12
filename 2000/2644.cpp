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

#define MAX_N 100

int n;
int f, t;
int m;

vector<int> adj[MAX_N];

int bfs() {
	queue<int> q;
	int dist[MAX_N];
	memset(dist, -1, sizeof(dist));
	q.emplace(f);
	dist[f] = 0;

	while (q.size()) {
		int here = q.front();
		q.pop();

		if (here == t)
			return dist[t];

		for (auto e : adj[here]) 
			if (dist[e] == -1) {
				dist[e] = dist[here] + 1;
				q.emplace(e);
			}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	cin >> f >> t;
	f--;
	t--;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	cout << bfs() << endl;

	return 0;
}