#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

enum Direction { UP, DOWN, LEFT, RIGHT };

int n, m;
vector<int> rowMirror[MAX_N];
vector<int> rowMirrorRev[MAX_N];
vector<int> columnMirror[MAX_N];
vector<int> columnMirrorRev[MAX_N];

int ans[MAX_N * 4];

int getAns(int hereY, int hereX, Direction direction) {
	switch (direction) {
	case UP: {
		auto iter = lower_bound(columnMirrorRev[hereX].begin(), columnMirrorRev[hereX].end(), hereY - 1, greater<int>());
		if (iter == columnMirrorRev[hereX].end())
			return (n + m) * 2 - hereX;

		return getAns(*iter, hereX, RIGHT);
	}
	case DOWN: {
		auto iter = lower_bound(columnMirror[hereX].begin(), columnMirror[hereX].end(), hereY + 1);
		if (iter == columnMirror[hereX].end())
			return (n + 1) + hereX;

		return getAns(*iter, hereX, LEFT);
	}
	case RIGHT: {
		auto iter = lower_bound(rowMirror[hereY].begin(), rowMirror[hereY].end(), hereX + 1);
		if (iter == rowMirror[hereY].end())
			return (n * 2 + m) - hereY;

		return getAns(hereY, *iter, UP);
	}
	case LEFT: {
		auto iter = lower_bound(rowMirrorRev[hereY].begin(), rowMirrorRev[hereY].end(), hereX - 1, greater<int>());
		if (iter == rowMirrorRev[hereY].end())
			return hereY + 1;

		return getAns(hereY, *iter, DOWN);
	}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				rowMirror[i].push_back(j);
				rowMirrorRev[i].push_back(j);
				columnMirror[j].push_back(i);
				columnMirrorRev[j].push_back(i);
			}
		}

	for (int i = 0; i < n; i++) {
		if (rowMirror[i].size())
			sort(rowMirror[i].begin(), rowMirror[i].end());
		if (rowMirrorRev[i].size())
			sort(rowMirrorRev[i].begin(), rowMirrorRev[i].end(), greater<int>());
	}
	for (int i = 0; i < m; i++) {
		if (columnMirror[i].size())
			sort(columnMirror[i].begin(), columnMirror[i].end());
		if (columnMirrorRev[i].size())
			sort(columnMirrorRev[i].begin(), columnMirrorRev[i].end(), greater<int>());
	}

	for (int i = 0; i < n; i++) {
		int ret = getAns(i, -1, RIGHT);
		ans[i] = ret;
		ans[ret - 1] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		int ret = getAns(n, i, UP);
		ans[n + i] = ret;
		ans[ret - 1] = (n + i + 1);
	}
	for (int i = 0; i < (n + m) * 2; i++)
		cout << ans[i] << ' ';


	return 0;
}
