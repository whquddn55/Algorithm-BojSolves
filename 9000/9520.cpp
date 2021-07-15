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
#define MAX_N 1505
#define MOD 1000000007

int n;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int getDp(int idx1, int idx2) {
	if (idx1 > idx2)
		swap(idx1, idx2);
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = INF;
	if (idx1 == idx2 - 1)
		for (int i = 0; i < idx1; ++i)
			ret = min(getDp(idx1, i) + arr[i][idx2], ret);
	else
		ret = getDp(idx1, idx2 - 1) + arr[idx2 - 1][idx2];
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	dp[0][1] = dp[1][0] = arr[0][1];
	int ans = INF;
	for (int i = 0; i < n; ++i)
		ans = min(getDp(i, n - 1), ans);
	cout << ans << endl;

	return 0;
}
