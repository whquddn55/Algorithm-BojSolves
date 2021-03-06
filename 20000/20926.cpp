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

#define MAX_N 505
#define MOD 1000000007

int w, h;
char arr[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

void dijkstra(pii start) {
	for (int i = 0; i < h; ++i)
		fill(dist[i], dist[i] + w, INF);
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.emplace(0, start);
	dist[start.first][start.second] = 0;

	while (pq.size()) {
		int hereY = pq.top().second.first;
		int hereX = pq.top().second.second;
		int hereDist = pq.top().first;
		pq.pop();

		if (hereDist < dist[hereY][hereX])
			continue;

		int nextDist = hereDist;
		for (int nextY = hereY + 1; nextY < h; ++nextY) {
			if (arr[nextY][hereX] < 10)
				nextDist += arr[nextY][hereX];
			else if (arr[nextY][hereX] == 'R') {
				if (nextDist < dist[nextY - 1][hereX]) {
					pq.emplace(nextDist, pii(nextY - 1, hereX));
					dist[nextY - 1][hereX] = nextDist;
				}
				break;
			}
			else if (arr[nextY][hereX] == 'E') {
				if (nextDist < dist[nextY][hereX]) 
					dist[nextY][hereX] = nextDist;
				break;
			}
			else if (arr[nextY][hereX] == 'H')
				break;
		}

		nextDist = hereDist;
		for (int nextY = hereY - 1; nextY >= 0; --nextY) {
			if (arr[nextY][hereX] < 10)
				nextDist += arr[nextY][hereX];
			else if (arr[nextY][hereX] == 'R') {
				if (nextDist < dist[nextY + 1][hereX]) {
					pq.emplace(nextDist, pii(nextY + 1, hereX));
					dist[nextY + 1][hereX] = nextDist;
				}
				break;
			}
			else if (arr[nextY][hereX] == 'E') {
				if (nextDist < dist[nextY][hereX])
					dist[nextY][hereX] = nextDist;
				break;
			}
			else if (arr[nextY][hereX] == 'H')
				break;
		}

		nextDist = hereDist;
		for (int nextX = hereX - 1; nextX >= 0; --nextX) {
			if (arr[hereY][nextX] < 10)
				nextDist += arr[hereY][nextX];
			if (arr[hereY][nextX] == 'R') {
				if (nextDist < dist[hereY][nextX + 1]) {
					pq.emplace(nextDist, pii(hereY, nextX + 1));
					dist[hereY][nextX + 1] = nextDist;
				}
				break;
			}
			else if (arr[hereY][nextX] == 'E') {
				if (nextDist < dist[hereY][nextX ])
					dist[hereY][nextX] = nextDist;
				break;
			}
			else if (arr[hereY][nextX] == 'H')
				break;
		}

		nextDist = hereDist;
		for (int nextX = hereX + 1; nextX < w; ++nextX) {
			if (arr[hereY][nextX] < 10)
				nextDist += arr[hereY][nextX];
			if (arr[hereY][nextX] == 'R') {
				if (nextDist < dist[hereY][nextX - 1]) {
					pq.emplace(nextDist, pii(hereY, nextX - 1));
					dist[hereY][nextX - 1] = nextDist;
				}
				break;
			}
			else if (arr[hereY][nextX] == 'E') {
				if (nextDist < dist[hereY][nextX])
					dist[hereY][nextX] = nextDist;
				break;
			}
			else if (arr[hereY][nextX] == 'H')
				break;
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> w >> h;
	pii start;
	pii dest;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			cin >> arr[i][j];
			if (!isalpha(arr[i][j]))
				arr[i][j] -= '0';
			else if (arr[i][j] == 'T')
				start = pii(i, j);
			else if (arr[i][j] == 'E')
				dest = pii(i, j);
		}

	dijkstra(start);
	cout << (dist[dest.first][dest.second] == INF ? -1 : dist[dest.first][dest.second]) << endl;

	
	
	return 0;
}