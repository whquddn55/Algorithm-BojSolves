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

int n, m;
char arr[MAX_N][MAX_N];
ll pSum[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
		}


	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) 
			pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + arr[i][j];
		
	ll ret = 0;
	// case 1
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			ret = max({ ret,
						pSum[i][j] * (pSum[i][m] - pSum[i][j]) * (pSum[n][m] - pSum[i][m]),
						pSum[i][m] * (pSum[n][j] - pSum[i][j]) * (pSum[n][m] - pSum[n][j] - pSum[i][m] + pSum[i][j]),
						pSum[i][j] * (pSum[n][j] - pSum[i][j]) * (pSum[n][m] - pSum[n][j]),
						pSum[n][j] * (pSum[i][m] - pSum[i][j]) * (pSum[n][m] - pSum[n][j] - pSum[i][m] + pSum[i][j])
				});
		}
	// case 2
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			ret = max(ret, pSum[i][m] * (pSum[j][m] - pSum[i][m]) * (pSum[n][m] - pSum[j][m]));

	for (int i = 1; i <= m; ++i)
		for (int j = i + 1; j <= m; ++j)
			ret = max(ret, pSum[n][i] * (pSum[n][j] - pSum[n][i]) * (pSum[n][m] - pSum[n][j]));
		
	cout << ret << endl;

	
	return 0;
}