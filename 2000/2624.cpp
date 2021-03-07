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

#define MAX_N 105
#define MOD 1000000007

int t, k;
pii arr[MAX_N];
int dp[10001][MAX_N];

int getDp(int remain, int index) {
	if (index == k) 
		return (remain == 0);

	int& ret = dp[remain][index];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i <= arr[index].second; ++i) {
		if (remain < arr[index].first * i)
			break;
		ret += getDp(remain - arr[index].first* i, index + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> t >> k;
	for (int i = 0; i < k; ++i)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << getDp(t, 0) << endl;
	
	return 0;
}