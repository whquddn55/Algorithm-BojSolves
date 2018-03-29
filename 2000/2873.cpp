#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int r, c;
vector<vector<int>> arr;

bool bound(int y, int x) {
	return !(y >= r || y < 0 || x >= c || x < 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> c;
	arr.resize(r, vector<int>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];

	if (r % 2) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c - 1; j++) {
				cout << (i % 2 ? 'L' : 'R');
			}
			if (i != r - 1)
				cout << 'D';
		}
	}
	else if (c % 2) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r - 1; j++) {
				cout << (i % 2 ? 'U' : 'D');
			}
			if (i != c - 1)
				cout << 'R';
		}
	}
	else {
		int minValue = INF;
		pii toExclude;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 == 1 && minValue > arr[i][j]) {
					minValue = arr[i][j];
					toExclude = { i, j };
				}
			}
		arr[toExclude.first][toExclude.second] = -1;

		for (int i = 0; i < toExclude.first - (toExclude.first % 2); i++) {
			for (int j = 0; j < c - 1; j++) {
				cout << (i % 2 ? 'L' : 'R');
			}
			cout << 'D';
		}

		pii here(toExclude.first - (toExclude.first % 2), 0);
		int dy[] = { 1, 0, -1, 0 };
		int dx[] = { 0, 1, 0, 1 };
		char print[] = { 'D', 'R', 'U', 'R' };
		int i = 0;
		while ((here.first != (toExclude.first - (toExclude.first % 2) + 1)) || (here.second != c - 1)) {
			if (arr[here.first + dy[i]][here.second + dx[i]] == -1) {
				i--;
				if (i < 0)
					i += 4;
			}
			else {
				cout << print[i];
				here.first += dy[i];
				here.second += dx[i];
				i++;
				i %= 4;
			}
		}
		if (here.first != r - 1)
			cout << 'D';
		for (int i = (toExclude.first - (toExclude.first % 2) + 2); i < r; i++) {
			for (int j = 0; j < c - 1; j++) {
				cout << (i % 2 ? 'R' : 'L');
			}
			if (i != r - 1)
				cout << 'D';
		}
	}

	


	return 0;
}
