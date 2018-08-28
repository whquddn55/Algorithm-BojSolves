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

int n;
int k;
int dist[MAX_N][30];
vector<int> arr[MAX_N];

int bfs() {
	for (int i = 0; i < MAX_N; i++)
		fill_n(dist[i], 30, INF);
	queue<pair<pii, int>> q;
	q.emplace(pii(-1, 1), 0);
	
	int ans = INF;
	while (!q.empty()) {
		int hereIndex = q.front().first.first;
		int hereHeight = q.front().first.second;
		int hereCost = q.front().second;
		q.pop();

		if (hereIndex == n - 1) {
			ans = min(ans, hereCost);
			continue;
		}

		for (auto nextHeight : arr[hereIndex + 1]) {
			int nextCost;
			if (abs(nextHeight - hereHeight) <= 1 || (hereHeight <= 10 ? (nextHeight == hereHeight * 2) : (nextHeight == 20)))
				nextCost = hereCost;
			else
				nextCost = hereCost + 1;

			if (nextCost == k + 1)
				continue;

			if (dist[hereIndex + 1][nextHeight] > nextCost) {
				dist[hereIndex + 1][nextHeight] = nextCost;
				q.emplace(pii(hereIndex + 1, nextHeight), nextCost);
			}
		}
	}
	return ans == INF ? -1 : ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		while (m--) {
			int t;
			cin >> t;
			arr[i].emplace_back(t);
		}
	}

	cout << bfs() << endl;

	return 0;
}
