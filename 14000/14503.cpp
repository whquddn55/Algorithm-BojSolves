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

#define INF (LLONG_MAX / 2)

#define MAX_N 50

int n, m;
int arr[MAX_N][MAX_N];
pair<pii, int> status;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int dy2[] = { 1, 0, -1, 0 };
int dx2[] = { 0, -1, 0, 1 };

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	cin >> status;
	status.first.first;
	status.first.second;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (true) {
		if (!arr[status.first.first][status.first.second])
			ans++;
		arr[status.first.first][status.first.second] = 2;

		bool check = false;
		for (int i = 0; i < 4; i++) {
			int nextY = status.first.first + dy[status.second];
			int nextX = status.first.second + dx[status.second];
			status.second--;
			status.second = (status.second == -1) ? 3 : status.second;

			if (arr[nextY][nextX])
				continue;

			status.first.first = nextY;
			status.first.second = nextX;
			check = true;

			break;
		}
		if (check)
			continue;

		int nextY = status.first.first + dy2[status.second];
		int nextX = status.first.second + dx2[status.second];
		if (arr[nextY][nextX] == 1)
			break;

		status.first.first = nextY;
		status.first.second = nextX;
	}

	cout << ans << endl;

	return 0;
}