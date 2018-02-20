#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<bool> column;
vector<bool> rd;
vector<bool> lu;
int result = 0;

void placeQueen(int row) {
	if (row == n) {
		result++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!column[i] && !rd[row + i] && !lu[n - (row - i)]) {
			column[i] = true;
			rd[row + i] = true;
			lu[n - (row - i)] = true;

			placeQueen(row + 1);

			column[i] = false;
			rd[row + i] = false;
			lu[n - (row - i)] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	column.resize(n, false);
	rd.resize(n * 2, false);
	lu.resize(n * 2, false);

	placeQueen(0);
	printf("%d\n", result);
	return 0;
}
