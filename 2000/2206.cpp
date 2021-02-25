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

#define MAX_N 1000
#define MOD 1000000007

int n, m;
char arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
		}

	queue<pair<pii, pii>> q;
	q.emplace(pii(0, 0), pii(0, 1));
	visited[0][0][0] = true;

	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	int result = -1;
	while (q.size()) {
		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		bool used = q.front().second.first;
		int dist = q.front().second.second;
		q.pop();

		if (hereY == n - 1 && hereX == m - 1) {
			result = dist;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
				continue;
			if (used) {
				if (arr[nextY][nextX])
					continue;
				if (visited[nextY][nextX][true])
					continue;

				visited[nextY][nextX][true] = true;
				q.emplace(pii(nextY, nextX), pii(true, dist+ 1));
			}
			else {
				if (arr[nextY][nextX]) {
					if (visited[nextY][nextX][true])
						continue;
					visited[nextY][nextX][true] = true;
					q.emplace(pii(nextY, nextX), pii(true, dist + 1));
				}
				else {
					if (visited[nextY][nextX][false])
						continue;
					visited[nextY][nextX][false] = true;
					q.emplace(pii(nextY, nextX), pii(false, dist + 1));
				}
			}
		}
	}

	cout << result << endl;


	return 0;
}