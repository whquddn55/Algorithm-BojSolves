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

#define MAX_N 1000

int n;
int arr[MAX_N];
int dp[MAX_N];

int getDp(int idx1) {
	if (idx1 == n - 1)
		return 0;
	if (idx1 >= n)
		return INF;
	int& ret = dp[idx1];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 1; i <= arr[idx1]; i++)
		ret = min(ret, getDp(idx1 + i) + 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	int res = getDp(0);
	cout << (res == INF ? -1 : res) << endl;
	
	return 0;
}