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

#define MAX_N 10005
#define MOD 1000000007

int n, k;
pii arr[MAX_N];
int dp[1005][MAX_N];

int getDp(int idx1, int idx2) {
	if (idx1 == k) 
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;


	ret = getDp(idx1 + 1, idx2);
	if (arr[idx1].second <= idx2)
		ret = max(ret, getDp(idx1 + 1, idx2 - arr[idx1].second) + arr[idx1].first);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; ++i)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << getDp(0, n) << endl;
	
	return 0;
}