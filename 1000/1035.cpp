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

#define MAX_N 5

vector<vector<char>> init(MAX_N);
map<vector<vector<char>>, int> m;
queue<pair<vector<vector<char>>, vector<pii>>> q;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

int dotCnt = 0;

bool checkBound(int y, int x) {
	return (y < 5 && y >= 0 && x < 5 && x >= 0);
}

bool bfs(vector<vector<char>>& arr, pii e) {
	queue<pii> q;
	q.emplace(e);
	bool visited[MAX_N][MAX_N];
	memset(visited, false, sizeof(visited));
	visited[e.first][e.second] = true;

	int cnt = 1;
	while (!q.empty()) {
		pii here = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = here.first + dy[i];
			int nextX = here.second + dx[i];

			if (!checkBound(nextY, nextX))
				continue;
			if (visited[nextY][nextX])
				continue;
			if (arr[nextY][nextX] == '.')
				continue;

			q.emplace(nextY, nextX);
			visited[nextY][nextX] = true;
			cnt++;
		}
	}

	return cnt == dotCnt;
}

int get(vector<pii>& p) {
	q.emplace(init, p);
	m[init] = 1;

	while (!q.empty()) {
		vector<vector<char>> here = q.front().first;
		vector<pii> pos = q.front().second;
		int cnt = m[here];
		q.pop();

		if (bfs(here, pos[0]))
			return cnt - 1;

		for (auto& e : pos) {
			for (int j = 0; j < 4; j++) {
				if (!checkBound(e.first + dy[j], e.second + dx[j]))
					continue;
				if (here[e.first + dy[j]][e.second + dx[j]] == '*')
					continue;

				swap(here[e.first][e.second], here[e.first + dy[j]][e.second + dx[j]]);

				if (!m[here]) {
					m[here] = cnt + 1;
					e.first += dy[j];
					e.second += dx[j];

					q.emplace(here, pos);

					e.first -= dy[j];
					e.second -= dx[j];
				}
				swap(here[e.first][e.second], here[e.first + dy[j]][e.second + dx[j]]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	for (int i = 0; i < MAX_N; i++) {
		init[i].resize(MAX_N);
		for (int j = 0; j < MAX_N; j++) {
			cin >> init[i][j];
			if (init[i][j] == '*')
				dotCnt++;
		}
	}

	vector<pii> pos;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (init[i][j] == '*')
				pos.emplace_back(i, j);

	cout << get(pos) << endl;

	return 0;
}
