#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

#define MAX_N 1001
#define MAX_M 100001
#define MAX_Q 200001

int n, m, q;
bool erase[MAX_M];
pii edge[MAX_M];
pii command[MAX_Q];
vector<int> adj[MAX_N];

int dist[MAX_N];
stack<int> st;

void bfs(int start) {
	queue<pii> q;
	q.emplace(start, dist[start]);

	while (!q.empty()) {
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();

		for (int next : adj[here]) {
			if (dist[next] > cost + 1) {
				dist[next] = cost + 1;
				q.emplace(next, cost + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		edge[i] = { u, v };
	}

	for (int i = 0; i < q; i++) {
		char c;
		int p;
		cin >> c >> p;
		p--;
		if (c == 'U') {
			command[i] = { 0, p };
			erase[p] = true;
		}
		else
			command[i] = { 1, p };
	}

	for (int i = 0; i < m; i++)
		if (!erase[i])
			adj[edge[i].first].push_back(edge[i].second);

	fill_n(dist, MAX_N, INF);
	dist[0] = 0;
	bfs(0);

	for (int i = q - 1; i >= 0; --i) {
		if (command[i].first == 1)
			st.push(dist[command[i].second] == INF ? -1 : dist[command[i].second]);
		else {
			adj[edge[command[i].second].first].push_back(edge[command[i].second].second);
			bfs(edge[command[i].second].first);
		}
	}

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}