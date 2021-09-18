#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 101010;
const ll INF = 9e15;
const ll MOD = 1'000'000'007;

int n;
int a, b, c;
int startX, startY;
int m;
pll arr[5];
priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll> > > pq;
int dist[55][55][20];

int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[8] = { -2, -1, 1, 2 ,2 , 1, -1, -2 };

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n;
	cin >> a >> b >> c;
	cin >> startX >> startY;
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> arr[i].first >> arr[i].second;


	pq.emplace(pll(0, 0), pll(startY, startX));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			fill_n(dist[i][j], 20, INT_MAX / 2);
	}
	dist[startY][startX][0] = 0;
	while (pq.size()) {
		int hereY = pq.top().second.first;
		int hereX = pq.top().second.second;
		int hereCost = pq.top().first.first;
		int hereStatus = pq.top().first.second;
		pq.pop();

		if (hereCost > dist[hereY][hereX][hereStatus])
			continue;
		
		for (int i = 0; i < 8; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];
			int nextCost = hereCost + a;
			int nextStatus = hereStatus;

			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0) 
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;
			
			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}

		for (int i = 0; i < n; ++i) {
			int nextY = i;
			int nextX = hereX;
			int nextCost = hereCost + c;
			int nextStatus = hereStatus;

			if (nextY == hereY && nextX == hereX)
				continue;
			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;

			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}
		for (int i = 0; i < n; ++i) {
			int nextY = hereY;
			int nextX = i;
			int nextCost = hereCost + c;
			int nextStatus = hereStatus;
			if (nextY == hereY && nextX == hereX)
				continue;
			
			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;

			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}
		for (int i = 0; i < n; ++i) {
			int nextY = hereY - i;
			int nextX = hereX - i;
			int nextCost = hereCost + b;
			int nextStatus = hereStatus;

			if (nextY == hereY && nextX == hereX)
				continue;
			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;

			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}
		for (int i = 0; i < n; ++i) {
			int nextY = hereY + i;
			int nextX = hereX + i;
			int nextCost = hereCost + b;
			int nextStatus = hereStatus;

			if (nextY == hereY && nextX == hereX)
				continue;
			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;

			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}
		for (int i = 0; i < n; ++i) {
			int nextY = hereY - i;
			int nextX = hereX + i;
			int nextCost = hereCost + b;
			int nextStatus = hereStatus;

			if (nextY == hereY && nextX == hereX)
				continue;
			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;

			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}
		for (int i = 0; i < n; ++i) {
			int nextY = hereY + i;
			int nextX = hereX - i;
			int nextCost = hereCost + b;
			int nextStatus = hereStatus;

			if (nextY == hereY && nextX == hereX)
				continue;
			for (int j = 0; j < m; ++j)
				if (pll(nextX, nextY) == arr[j])
					nextStatus |= (1 << j);

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (dist[nextY][nextX][nextStatus] <= nextCost)
				continue;

			dist[nextY][nextX][nextStatus] = nextCost;
			pq.emplace( pll(nextCost, nextStatus), pll(nextY, nextX));
		}
	}

	int ret = INT_MAX;
	for (int i = 0; i < m; ++i)
		ret = min(ret, dist[arr[i].second][arr[i].first][(1 << m) - 1]);
	cout << ret << endl;
}