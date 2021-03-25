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

#define MAX_N 51

int n;
int arr[MAX_N];
int power[MAX_N];
int d;

int dp[105][MAX_N][105];

int getDp(int idx1, int idx2, int idx3) {
	if (idx2 == n - 1)
		return 0;
	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i <= idx3 + arr[idx2]; ++i) {
		if (idx1 < i)
			break;
		ret = max(ret, getDp(idx1 - i, idx2 + 1, i) + (power[idx2 + 1] - power[idx2]) * i);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		cin >> power[i];
	cin >> d;

	ll result = 0;
	for (int i = 0; i < n; ++i)
		result += (ll)arr[i] * power[i];

	memset(dp, -1, sizeof(dp));
	cout << result + getDp(d, 0, 0) << endl;

	return 0;
}