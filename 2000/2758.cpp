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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 10
#define MAX_M 2001

int n, m;
int ans;

ll dp[MAX_N][MAX_M];

ll get(int pos, int minValue) {
	if (pos == n)
		return minValue <= m * 2;

	ll& ret = dp[pos][minValue];
	if (ret != -1)
		return ret;

	ret = 0;
	int t = 1;
	for (int i = 0; i < n - pos - 1; i++)
		t *= 2;

	int maxValue = m / t;
	for (int i = minValue; i <= maxValue; i++)
		ret += get(pos + 1, i * 2);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		ans = 0;
		cin >> n >> m;

		cout << get(0, 1) << endl;
	}

	return 0;
}
