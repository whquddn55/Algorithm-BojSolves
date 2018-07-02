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

#define MAX_N 301

int n, q;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][11];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k < 11; k++) 
				dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] + (arr[i][j] == k) - dp[i - 1][j - 1][k];

	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		map<int, int> m;
		for (int i = 0; i < 11; i++)
				m[i] += dp[y2][x2][i];
		for (int i = 0; i < 11; i++)
				m[i] -= dp[y2][x1 - 1][i];
			
		for (int i = 0; i < 11; i++)
				m[i] -= dp[y1 - 1][x2][i];
		for (int i = 0; i < 11; i++)
				m[i] += dp[y1 - 1][x1 - 1][i];

		int ans = 0;
		for (auto& e : m)
			if (e.second)
				ans++;
		cout << ans << endl;
	}

	return 0;
}
