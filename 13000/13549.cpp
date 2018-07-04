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

#define MAX_N 100001

int n, k;
int ans = 0;
int dist[MAX_N];

void dijkstra() {
	fill(dist, dist + MAX_N, INF);
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.emplace(0, n);
	dist[n] = 0;
	
	while (!q.empty()) {
		int time = q.top().first;
		int here = q.top().second;
		q.pop();

		int d[3] = { -1, 1, here };
		int t[3] = { 1, 1, 0 };
		for (int i = 0; i < 3; i++) {
			int next = here + d[i];

			if (next >= 0 && next < MAX_N && (dist[next] > dist[here] + t[i])) {
				q.emplace(time + t[i], next);
				dist[next] = dist[here] + t[i];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	dijkstra();

	cout << dist[k] << endl;

	return 0;
}
