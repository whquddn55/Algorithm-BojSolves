#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 101

int n;
char arr[MAX_N][MAX_N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != '#')
				arr[i][j] -= '0';
		}
	if (n > 3)
		ans += (n - 4) * (n - 4);

	int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int i = 1; i < n - 1; i++) {
		int y[] = { i, 1, i, n - 2 };
		int x[] = { 1, i, n - 2, i };
		for (int j = 0; j < 4; j++) {
			int hereY = y[j];
			int hereX = x[j];
			bool existZero = false;
			for (int i = 0; i < 8; i++) {
				int nextY = hereY + dy[i];
				int nextX = hereX + dx[i];

				if (arr[nextY][nextX] == 0)
					existZero = true;
			}
			if (!existZero) {
				for (int k = 0; k < 8; k++) {
					int nextY = hereY + dy[k];
					int nextX = hereX + dx[k];

					if (arr[nextY][nextX] != '#')
						arr[nextY][nextX]--;
				}
				ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}