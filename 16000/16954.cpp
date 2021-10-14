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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 100005

char arr[8][8];
bool visited[8][8][20];

int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
bool bfs() {
	queue<pair<pii, int>> q;
	q.emplace(pii(7, 0), 0);
	visited[7][0][0] = 0;

	while(q.size()) {
		int hY = q.front().first.first;
		int hX = q.front().first.second;
		int round = q.front().second;
		q.pop();

		if (hY == 0 && hX == 0)
			return true;
		
		for (int i = 0; i < 9; ++i) {
			int nY = hY + dy[i];
			int nX = hX + dx[i];

			if (nY < 0 || nY >= 8 || nX < 0 || nX >= 8)
				continue;
			if (visited[nY][nX][round + 1])
				continue;
			if ((nY - round) >= 0 && (arr[nY - round][nX] == '#'))
				continue;
			if ((nY - round - 1) >= 0 && (arr[nY - round - 1][nX] == '#'))
				continue;
			q.emplace(pii(nY, nX), round + 1);
			visited[nY][nX][round + 1] = true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			cin >> arr[i][j];

	cout << bfs() << endl;

	return 0;
}