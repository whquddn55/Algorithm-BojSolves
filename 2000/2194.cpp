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

#define MAX_N 500

int n, m, a, b, k;
bool arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
pii startPoint, endPoint;

bool checkBlock(pii here) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			if (arr[here.first + i][here.second + j])
				return true;
	return false;
}

int bfs() {
	queue<pair<pii, int>> q;
	q.emplace(startPoint, 0);

	if (checkBlock(startPoint))
		return -1;
	if (startPoint == endPoint)
		return 0;

	visited[startPoint.first][startPoint.second] = true;

	int dy[] = { 0, -1, 0, 1 };
	int dx[] = { -1, 0, 1, 0 };
	while (!q.empty()) {
		pii here = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = here.first + dy[i];
			int nextX = here.second + dx[i];

			if (nextY < 0 || nextX < 0 || nextY + a > n || nextX + b > m)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (checkBlock({ nextY, nextX }))
				continue;

			q.emplace(pii(nextY, nextX), cnt + 1);
			visited[nextY][nextX] = true;
			if (pii(nextY, nextX) == endPoint)
				return cnt + 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		pii block;
		cin >> block;
		arr[block.first - 1][block.second - 1] = true;
	}
	cin >> startPoint;
	startPoint.first--;
	startPoint.second--;
	cin >> endPoint;
	endPoint.first--;
	endPoint.second--;

	cout <<	bfs() << endl;
	
	return 0;
}
