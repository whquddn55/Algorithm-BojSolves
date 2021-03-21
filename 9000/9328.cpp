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

#define MAX_N 105

int h, w;
char arr[MAX_N][MAX_N];
bool keys[300];
vector<pii> door[300];
stack<pii> startPoint;
bool visited[MAX_N][MAX_N];
int result;

void bfs() {
	queue<pii> q;
	while (startPoint.size()) {
		q.emplace(startPoint.top());
		visited[startPoint.top().first][startPoint.top().second] = true;
		startPoint.pop();
	}

	while (q.size()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();


		int dy[4] = { 0, -1, 0, 1 };
		int dx[4] = { -1, 0, 1, 0 };
		for (int i = 0; i < 4; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= h || nextY < 0 || nextX >= w || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;

			if (arr[nextY][nextX] == '*')
				continue;

			if (arr[nextY][nextX] == '.') {
				q.emplace(nextY, nextX);
				visited[nextY][nextX] = true;
			}
			else if (arr[nextY][nextX] == '$') {
				++result;
				arr[nextY][nextX] = '.';
				q.emplace(nextY, nextX);
				visited[nextY][nextX] = true;
			}
			else if (islower(arr[nextY][nextX])) {
				keys[arr[nextY][nextX]] = true;

				for (auto d : door[toupper(arr[nextY][nextX])]) {
					startPoint.emplace(d.first, d.second);
				}
				door[toupper(arr[nextY][nextX])].clear();

				arr[nextY][nextX] = '.';
				q.emplace(nextY, nextX);
				visited[nextY][nextX] = true;
			}
			else { // isupper
				if (keys[tolower(arr[nextY][nextX])]) {
					q.emplace(nextY, nextX);
					visited[nextY][nextX] = true;
				}
				else {
					door[arr[nextY][nextX]].emplace_back(nextY, nextX);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(keys, 0, sizeof(keys));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 300; ++i)
			door[i].clear();
		result = 0;


		cin >> h >> w;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) 
				cin >> arr[i][j];

		string temp;
		cin >> temp;
		if (temp.compare("0") != 0) {
			for (char t : temp) {
				keys[t] = true;
			}
		}

		for (int i = 0; i < h; ++i) {
			if (arr[i][0] == '.')
				startPoint.emplace(i, 0);
			else if (islower(arr[i][0])) {
				startPoint.emplace(i, 0);
				keys[arr[i][0]] = true;
			}
			else if (arr[i][0] == '$') {
				startPoint.emplace(i, 0);
				arr[i][0] = '.';
				++result;
			}
			else {
				if (keys[tolower(arr[i][0])])
					startPoint.emplace(i, 0);
				else
					door[arr[i][0]].emplace_back(i, 0);
			}

			if (arr[i][w - 1] == '.')
				startPoint.emplace(i, w - 1);
			else if (islower(arr[i][w - 1])) {
				startPoint.emplace(i, w - 1);
				keys[arr[i][w - 1]] = true;
			}
			else if (arr[i][w - 1] == '$') {
				startPoint.emplace(i, w - 1);
				arr[i][w - 1] = '.';
				++result;
			}
			else {
				if (keys[tolower(arr[i][w - 1])])
					startPoint.emplace(i, w - 1);
				else
					door[arr[i][w - 1]].emplace_back(i, w - 1);
			}
		}
		for (int i = 0; i < w; ++i) {
			if (arr[0][i] == '.')
				startPoint.emplace(0, i);
			else if (islower(arr[0][i])) {
				startPoint.emplace(0, i);
				keys[arr[0][i]] = true;
			}
			else if (arr[0][i] == '$') {
				startPoint.emplace(0, i);
				arr[0][i] = '.';
				++result;
			}
			else {
				if (keys[tolower(arr[0][i])])
					startPoint.emplace(0, i);
				else
					door[arr[0][i]].emplace_back(0, i);
			}

			if (arr[h - 1][i] == '.')
				startPoint.emplace(h - 1, i);
			else if (islower(arr[h - 1][i])) {
				startPoint.emplace(h - 1, i);
				keys[arr[h - 1][i]] = true;
			}
			else if (arr[h - 1][i] == '$') {
				startPoint.emplace(h - 1, i);
				arr[h - 1][i] = '.';
				++result;
			}
			else {
				if (keys[tolower(arr[h - 1][i])])
					startPoint.emplace(h - 1, i);
				else
					door[arr[h - 1][i]].emplace_back(h - 1, i);
			}
		}

		while (startPoint.size())
			bfs();

		cout << result << endl;
	}
	
	return 0;
}