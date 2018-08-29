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

#define MAX_N 1001

int n;
double l, r;
double dp[MAX_N][MAX_N];


double getDp(int idx1, int idx2) {
	if (idx1 == n)
		return idx2;
	double& ret = dp[idx1][idx2];
	if (ret >= -0.5) 
		return ret;

	return ret = l * (getDp(idx1 + 1, idx2 + 1) - 1) + r * (getDp(idx1 + 1, max(idx2 -1, 0)) + 1) + (1 - l - r) * (getDp(idx1 + 1, idx2));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout.precision(4);
	cout << fixed;

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n >> l >> r;

		for (int i = 0; i < MAX_N; i++)
			fill_n(dp[i], MAX_N, -1.0);
		cout << getDp(0, 0) << endl;
	}

	return 0;
}