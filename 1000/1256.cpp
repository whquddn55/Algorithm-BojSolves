#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101

int n, m, k;
unsigned long long nCr[MAX_SIZE + MAX_SIZE][MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i <= n + m; i++)
		nCr[i][0] = 1;
	for (int i = 1; i <= n + m; i++)
		for (int j = 1; j <= n; j++)
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];

	if (k > nCr[n + m][n]) {
		cout << -1 << endl;
		return 0;
	}

	int aCnt = n;
	int zCnt = m;
	while (true) {
		if (!aCnt) {
			while (zCnt--)
				cout << 'z';
			break;
		}
		else if (!zCnt) {
			while (aCnt--)
				cout << 'a';
			break;
		}
		else if (k > nCr[aCnt + zCnt - 1][aCnt - 1]) {
			cout << 'z';
			k -= nCr[aCnt + zCnt - 1][aCnt - 1];
			zCnt--;
		}
		else {
			cout << 'a';
			aCnt--;
		}
	}

	return 0;
}
