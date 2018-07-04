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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 501

int n, m;

int adj[MAX_N][MAX_N];
int dist[MAX_N]; // start에서의 거리(start는 0임)

void spfa(int start) {
	fill(dist, dist + n, INF);
	bool inQ[MAX_N] = { false, };
	queue<int> q;
	q.emplace(start);

	dist[start] = 0;
	inQ[start] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (int i = 0; i < n; i++) {
			if (adj[here][i] != -1) {
				int next = i;
				int cost = adj[here][i];

				if (dist[next] > dist[here] + cost) {
					dist[next] = dist[here] + cost;
					if (!inQ[next]) {
						q.emplace(next);
						inQ[next] = true;
					}
				}
			}
		}
	}
}

void removePath(int here) {
	for (int i = 0; i < n; i++)
		if (adj[i][here] != -1 && adj[i][here] + dist[i] == dist[here]) {
			adj[i][here] = -1;
			removePath(i);
		}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
		memset(adj, -1, sizeof(adj));
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		int s, d;
		cin >> s >> d;
		while (m--) {
			int u, v, c;
			cin >> u >> v >> c;
			adj[u][v] = c;
		}

		spfa(s);
		int t = dist[d];
		while (dist[d] == t && t != INF) {
			removePath(d);
			spfa(s);
		}
		if (dist[d] == INF)
			cout << -1 << endl;
		else
			cout << dist[d] << endl;
	}

	return 0;
}
