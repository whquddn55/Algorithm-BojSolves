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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 10

int n, m;
char arr[MAX_N][MAX_N];
bool isVisited[MAX_N][MAX_N][MAX_N][MAX_N][MAX_N + 1];

int ans = 0;

void get(int ry, int rx, int by, int bx, int cnt) {
	if (isVisited[ry][rx][by][bx][cnt])
		return;
	isVisited[ry][rx][by][bx][cnt] = true;
	if (ans || cnt == 10)
		return;

	{
		int nrx, nbx;
		int ret = 0; // 0 : 아무 상태 아님, 1 : 빨간공만 들어감, -1 : 파란공이 들어감
		for (int i = rx - 1; i >= 0; i--) {
			if (arr[ry][i] == '#') {
				nrx = i + 1;
				break;
			}
			if (arr[ry][i] == 'O') {
				ret = 1;
				break;
			}
		}
		for (int i = bx - 1; i >= 0; i--) {
			if (arr[by][i] == '#') {
				nbx = i + 1;
				break;
			}
			if (arr[by][i] == 'O') {
				ret = -1;
				break;
			}
		}
		if (ry == by && nrx == nbx) {
			if (rx > bx)
				nrx++;
			else
				nbx++;
		}


		if (ret == 1)
			ans = 1;
		else if (ret == 0) {
			swap(arr[ry][rx], arr[ry][nrx]);
			swap(arr[by][bx], arr[by][nbx]);
			get(ry, nrx, by, nbx, cnt + 1);
			swap(arr[ry][rx], arr[ry][nrx]);
			swap(arr[by][bx], arr[by][nbx]);
		}
	}

	{
		int nrx, nbx;
		int ret = 0; // 0 : 아무 상태 아님, 1 : 빨간공만 들어감, -1 : 파란공이 들어감
		for (int i = rx + 1; i < m; i++) {
			if (arr[ry][i] == '#') {
				nrx = i - 1;
				break;
			}
			if (arr[ry][i] == 'O') {
				ret = 1;
				break;
			}
		}
		for (int i = bx + 1; i < m; i++) {
			if (arr[by][i] == '#') {
				nbx = i - 1;
				break;
			}
			if (arr[by][i] == 'O') {
				ret = -1;
				break;
			}
		}
		if (ry == by && nrx == nbx) {
			if (rx < bx)
				nrx--;
			else
				nbx--;
		}


		if (ret == 1)
			ans = 1;
		else if (ret == 0) {
			swap(arr[ry][rx], arr[ry][nrx]);
			swap(arr[by][bx], arr[by][nbx]);
			get(ry, nrx, by, nbx, cnt + 1);
			swap(arr[ry][rx], arr[ry][nrx]);
			swap(arr[by][bx], arr[by][nbx]);
		}
	}

	{
		int nry, nby;
		int ret = 0; // 0 : 아무 상태 아님, 1 : 빨간공만 들어감, -1 : 파란공이 들어감
		for (int i = ry - 1; i >= 0; i--) {
			if (arr[i][rx] == '#') {
				nry = i + 1;
				break;
			}
			if (arr[i][rx] == 'O') {
				ret = 1;
				break;
			}
		}
		for (int i = by - 1; i >= 0; i--) {
			if (arr[i][bx] == '#') {
				nby = i + 1;
				break;
			}
			if (arr[i][bx] == 'O') {
				ret = -1;
				break;
			}
		}
		if (rx == bx && nry == nby) {
			if (ry > by)
				nry++;
			else
				nby++;
		}


		if (ret == 1)
			ans = 1;
		else if (ret == 0) {
			swap(arr[ry][rx], arr[nry][rx]);
			swap(arr[by][bx], arr[nby][bx]);
			get(nry, rx, nby, bx, cnt + 1);
			swap(arr[ry][rx], arr[nry][rx]);
			swap(arr[by][bx], arr[nby][bx]);
		}
	}

	{
		int nry, nby;
		int ret = 0; // 0 : 아무 상태 아님, 1 : 빨간공만 들어감, -1 : 파란공이 들어감
		for (int i = ry + 1; i < n; i++) {
			if (arr[i][rx] == '#') {
				nry = i - 1;
				break;
			}
			if (arr[i][rx] == 'O') {
				ret = 1;
				break;
			}
		}
		for (int i = by + 1; i < n; i++) {
			if (arr[i][bx] == '#') {
				nby = i - 1;
				break;
			}
			if (arr[i][bx] == 'O') {
				ret = -1;
				break;
			}
		}
		if (rx == bx && nry == nby) {
			if (ry < by)
				nry--;
			else
				nby--;
		}


		if (ret == 1)
			ans = 1;
		else if (ret == 0) {
			swap(arr[ry][rx], arr[nry][rx]);
			swap(arr[by][bx], arr[nby][bx]);
			get(nry, rx, nby, bx, cnt + 1);
			swap(arr[ry][rx], arr[nry][rx]);
			swap(arr[by][bx], arr[nby][bx]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	pii r, b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				r = { i, j };
			if (arr[i][j] == 'B')
				b = { i, j };
		}

	get(r.first, r.second, b.first, b.second, 0);
	cout << ans << endl;
		
	return 0;
}
