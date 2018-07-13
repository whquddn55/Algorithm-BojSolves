#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 11
#define MAX_M 221

int n, m, k;
ll dp[MAX_N][MAX_M][MAX_M];

ll getDp(int idx1, int idx2, int idx3) {
	if (idx1 == 1)
		return dp[idx1][idx2][idx3] = 1;

	ll& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = idx3; i <= idx2 / idx1; i++)
		ret += getDp(idx1 - 1, idx2 - i, i);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k;
	if (n == 1) {
		cout << m << endl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	getDp(n, m, 1);

	int toPrint = n - 1;
	int len = m;
	int prv = 1;
	while (toPrint >= 1) {
		for (int i = prv; i <= len; i++) {
			if (dp[toPrint][len - i][i] == -1)
				continue;
			if (dp[toPrint][len - i][i] < k)
				k -= dp[toPrint][len - i][i];
			else {
				cout << i << ' ';
				prv = i;
				len -= i;
				toPrint--;
				if (toPrint == 0)
					cout << len << endl;
				break;
			}
		}
	}
	return 0;
}