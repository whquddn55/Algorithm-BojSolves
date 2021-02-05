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

#define MAX_N 305

int n, m;
int arr[MAX_N][MAX_N];

int spfa() {
	queue<pii> q;
	bool inQ[MAX_N][MAX_N] = { 0, };
	int dist[MAX_N][MAX_N];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dist[i][j] = INF;
	q.emplace(pii(0, 0));
	inQ[0][0] = true;
	dist[0][0] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		inQ[y][x] = false;

		for (int i = 1; i <= arr[y][x] && y + i < n; ++i) {
			int nextY = y + i;
			int nextX = x;
			if (dist[nextY][nextX] > dist[y][x] + 1) {
				dist[nextY][nextX] = dist[y][x] + 1;
				if (!inQ[nextY][nextX]) {
					q.emplace(nextY, nextX);
					inQ[nextY][nextX];
				}
			}
		}
		for (int i = 1; i <= arr[y][x] && x + i < m; ++i) {
			int nextY = y;
			int nextX = x + i;
			if (dist[nextY][nextX] > dist[y][x] + 1) {
				dist[nextY][nextX] = dist[y][x] + 1;
				if (!inQ[nextY][nextX]) {
					q.emplace(nextY, nextX);
					inQ[nextY][nextX];
				}
			}
		}
	}

	return dist[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			cin >> arr[i][j];
		
	cout << spfa() << endl;

	return 0;
}