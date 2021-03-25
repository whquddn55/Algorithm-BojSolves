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

#define MAX_N 205

int n, t;
int c[MAX_N];
int e[MAX_N];
int dist[MAX_N][MAX_N];
int dp[1005][MAX_N];

int getDp(int idx1, int idx2) {
	if (idx1 == 0) {
		if (c[idx2] == 0)
			return 0;
		else
			return -INF;
	}

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = getDp(idx1 - 1, idx2) + e[idx2];
	for (int i = 0; i < n; ++i) {
		if (idx1 - dist[i][idx2] >= 0) {
			int prv = getDp(idx1 - dist[i][idx2], i);
			if (prv >= c[idx2])
				ret = max(ret, prv);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cin >> c[i] >> e[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> dist[i][j];

	memset(dp, -1, sizeof(dp));
	int result = 0;
	for (int i = 0; i < n; ++i)
		result = max(result, getDp(t, i));
	cout << result << endl;

	return 0;
}