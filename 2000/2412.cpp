#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_H 101

int n, t;
set<pii> s;

int dy[] = { -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
int dx[] = { -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2 };

int bfs() {
	queue<pair<pii, int>> q;
	q.emplace(make_pair(0, 0), 0);

	while (!q.empty()) {
		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		for (int i = 0; i < 24; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (s.count({ nextX, nextY }) == 0)
				continue;

			s.erase({ nextX, nextY });
			q.emplace(make_pair(nextY, nextX), cost + 1);

			if (nextY == t)
				return cost + 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		s.insert({x, y});
	}

	cout << bfs() << endl;

	return 0;
}
