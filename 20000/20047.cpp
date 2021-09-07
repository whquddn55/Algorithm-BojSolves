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
#define MAX_N 10005
#define MOD 1000000007
#define MOD2 1000000009

int n;
string s1, s2;
int dp[MAX_N][3];
char l, r;

int getDp(int i1, int i2) { // i2 : diff 
	if (i1 == n) 
		return (i2 == 2);
	int& ret = dp[i1][i2];
	if (ret != -1)
		return ret;

	ret = false;
	if (s1[i1 - i2] == s2[i1]) 
		ret |= getDp(i1 + 1, i2);

	if (i2 == 0 && (s2[i1] == l))
		ret |= getDp(i1 + 1, 1);
	else if (i2 == 1 && (s2[i1] == r))
		ret |= getDp(i1 + 1, 2);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);


	memset(dp, -1, sizeof(dp));
	cin >> n;
	cin >> s1 >> s2;
	int li, ri;
	cin >> li >> ri;
	l = s1[li];
	r = s1[ri];

	int idx = 0;
	for (int i = 0; i < n; ++i, ++idx) {
		if (li == i || ri == i) {			
			--idx;
			continue;
		}
		s1[idx] = s1[i];
	}
	s1[n - 1] = s1[n - 2] = '1';

	cout << (getDp(0, 0) ? "YES" : "NO") << endl;
	
	return 0;
}
