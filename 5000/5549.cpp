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

#define MAX_N 1001

int n, m;
int k;
char arr[MAX_N][MAX_N];
int dp1[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];
int dp3[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	cin >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp1[i][j] = dp1[i][j - 1] + dp1[i - 1][j] - dp1[i - 1][j - 1] + (arr[i][j] == 'J');
			dp2[i][j] = dp2[i][j - 1] + dp2[i - 1][j] - dp2[i - 1][j - 1] + (arr[i][j] == 'O');
			dp3[i][j] = dp3[i][j - 1] + dp3[i - 1][j] - dp3[i - 1][j - 1] + (arr[i][j] == 'I');
		}

	while (k--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << dp1[c][d] - dp1[a - 1][d] - dp1[c][b - 1] + dp1[a - 1][b - 1] << ' ' << 
			dp2[c][d] - dp2[a - 1][d] - dp2[c][b - 1] + dp2[a - 1][b - 1] << ' ' << 
			dp3[c][d] - dp3[a - 1][d] - dp3[c][b - 1] + dp3[a - 1][b - 1] << endl;
	}
		
	return 0;
}
