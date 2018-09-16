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

int t, w;
int arr[MAX_N];
int dp[MAX_N][31];

int getDp(int idx1, int idx2) {
	if (idx1 == t)
		return 0;
	if (idx2 > w)
		return 0;
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = 0;
	if (idx2 % 2 == arr[idx1])
		ret++;

	return ret += max(getDp(idx1 + 1, idx2 + 1), getDp(idx1 + 1, idx2));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t >> w;
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	memset(dp, -1, sizeof(dp));
	cout << max(getDp(0, 0), getDp(0, 1)) << endl;

	return 0;
}