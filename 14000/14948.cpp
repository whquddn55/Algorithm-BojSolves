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

#define MAX_N 100
#define MOD 1000000007

int n, m;
int arr[MAX_N][MAX_N];

bool decide(int level) {
	queue<pair<pii, bool>> q;
	bool visited[MAX_N][MAX_N][2] = { false, };

	if (arr[0][0] <= level) {
		q.emplace(pii(0, 0), false);
		visited[0][0][false] = true;
	}

	while (q.size()) {
		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		bool used = q.front().second;
		q.pop();

		if (hereY == n - 1 && hereX == m - 1)
			return true;

		
		int dy[4] = { -1, 0, 1, 0 };
		int dx[4] = { 0, 1, 0, -1 };
		for (int i = 0; i < 4; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
				continue;

			if (arr[nextY][nextX] <= level) {
				if (visited[nextY][nextX][used])
					continue;
				visited[nextY][nextX][used] = true; 
				q.emplace(pii(nextY, nextX), used);
			}
			else {
				if (used)
					continue;
				nextY += dy[i];
				nextX += dx[i];

				if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
					continue;
				if (visited[nextY][nextX][true])
					continue;
				if (arr[nextY][nextX] > level)
					continue;
				visited[nextY][nextX][true] = true;
				q.emplace(pii(nextY, nextX), true);
			}
		}
	}
	return false;
}

int bs(int l, int r) {
	while (l < r) {
		int mid = (l + r) / 2;
		if (decide(mid))
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	cout << bs(0, MOD) << endl;


	return 0;
}