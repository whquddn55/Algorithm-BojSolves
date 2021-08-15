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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 15
#define MOD 1000000007

int n, k;
string arr[MAX_N];
int dp[10][1000];
int modValue[MAX_N][1000];
ll dp2[33000][105];

ll getDp2(int i1, int i2, int szSum) {
	ll& ret = dp2[i1][i2];
	if (ret != -1)
		return ret;
	
	if (i1 == (1 << n) - 1) 
		return ret = (i2 == 0);

	ret = 0;
	for (int i = 0; i < n; ++i) {
		int bit = (1 << i);
		if (i1 & bit)
			continue;
		ret += getDp2(i1 | bit, (i2 + modValue[i][szSum]) % k, szSum + arr[i].size());
	}
	return ret;
}


ll factorial(int a) {
	if (a == 1)
		return 1;
	return a * factorial(a - 1);
}

ll gcd(ll a, ll b) {
	if (b == 0) 
		return a;
	return gcd(b, a % b);
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	memset(dp2, -1, sizeof(dp2));

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> k;

	for (int i = 1; i < 10; ++i) {
		dp[i][0] = i % k;
		for (int j = 1; j < 1000; ++j) 
			dp[i][j] = (dp[i][j - 1] * (10 % k)) % k;
	}

	for (int i = 0; i < n; ++i) {
		int cnt = arr[i].size() - 1;
		for (char ch : arr[i])
			modValue[i][0] = (modValue[i][0] + dp[ch - '0'][cnt--]) % k;
		for (int j = 1; j < 1000; ++j)
			modValue[i][j] = (modValue[i][j - 1] * 10) % k;
	}

	ll ans = getDp2(0, 0, 0);
	ll p = factorial(n);
	ll gc = gcd(ans, p);

	cout << ans / gc << '/' << p / gc << endl;
	
	return 0;
}
