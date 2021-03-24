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
#define MOD 1000000007

#define MAX_N 100005

int n;
pair<pii, int> arr[MAX_N];
int dp[MAX_N];

int getDp(int idx1) {
	int& ret = dp[idx1];
	if (ret != -1)
		return ret;

	ret = 0;
	int nextIndex = lower_bound(arr, arr + n, pair<pii, int>(pii(arr[idx1].first.second + 1, 0), 0)) - arr;
	if (idx1 < n - 1)
		ret = getDp(idx1 + 1);
	ret = max(ret, getDp(nextIndex) + arr[idx1].second);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	memset(dp, -1, sizeof(dp));
	cout << getDp(0) << endl;


	return 0;
}