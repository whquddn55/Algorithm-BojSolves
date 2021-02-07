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

#define MAX_N 5005

string s;
ll dp[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s;
	for (auto& c : s)
		c -= '0';
	dp[0] = 1;
	dp[1] = (((s[0] == 2 && s[1] <= 6) || (s[0] == 1)) && s[1] != 0) ? 2 : 1;
	for (int i = 2; i < s.size(); ++i) {
		int oneDigit = s[i];
		int twoDigit = s[i - 1] * 10 + s[i];
		dp[i] = 0;
		if (twoDigit >= 10 && twoDigit <= 26)
			dp[i] += dp[i - 2];
		if (oneDigit != 0)
			dp[i] += dp[i - 1];
		dp[i] %= 1000000;
	}
	if (s[0] == 0 || s.size() > 1 && ((s[1] == 0 && s[0] > 2)))
		dp[s.size() - 1] = 0;
	cout << dp[s.size() - 1] << endl;

	return 0;
}