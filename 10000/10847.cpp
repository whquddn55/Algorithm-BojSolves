#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator<<(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 30001

int n, m;
int from, to;
int dist[MAX_N];
vector<int> arr[MAX_N];

int dijkstra() {
	fill_n(dist, n, INF);
	queue<int> q;
	q.emplace(from);
	bool inQ[MAX_N] = { false, };
	inQ[from] = true;
	dist[from] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		inQ[here] = false;

		for (auto& jump : arr[here]) {
			for (int i = 1; here + jump * i < n; i++) {
				int next = here + jump * i;
				int nextCost = i;

				if (dist[next] > dist[here] + nextCost) {
					dist[next] = dist[here] + nextCost;
					if (!inQ[next]) {	
						q.emplace(next);
						inQ[next] = true;
					}
				}
				if (binary_search(arr[next].begin(), arr[next].end(), jump))
					break;
			}
			for (int i = 1; here - jump * i >= 0; i++) {
				int next = here - jump * i;
				int nextCost = i;

				if (dist[next] > dist[here] + nextCost) {
					dist[next] = dist[here] + nextCost;
					if (!inQ[next]) {
						q.emplace(next);
						inQ[next] = true;
					}
				}
				if (binary_search(arr[next].begin(), arr[next].end(), jump))
					break;
			}
		}
	}

	return dist[to] == INF ? -1 : dist[to];
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int b, p;
		cin >> b >> p;
		arr[b].push_back(p);
		if (i == 0)
			from = b;
		if (i == 1)
			to = b;
	}

	for (int i = 0; i < MAX_N; i++) {
		sort(arr[i].begin(), arr[i].end());
		arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());
	}

	cout << dijkstra() << endl;

	return 0;
}