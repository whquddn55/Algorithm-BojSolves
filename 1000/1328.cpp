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
#define MAX_N 103
#define MOD 1000000007

int n, l, r;
int dp[MAX_N][MAX_N][MAX_N];
int nCr[MAX_N][MAX_N];

int getDp(int idx1, int idx2, int idx3) {
	if (idx1 == 1) {
		if (idx2 == 1 && idx3 == 1)
			return 1;
		return 0;
	}
	if (idx1 == 0 || idx2 == 0 || idx3 == 0)
		return 0;
	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;
	ret = 0;
	
	for (int i = idx2 - 1; i <= idx1 - idx3; i++) {
		ll left = 0;
		for (int j = 1; j <= i - idx2 + 2; ++j)
			left = (left + getDp(i, idx2 - 1, j)) % MOD;
		ll right = 0;
		for (int j = 1; j <= idx1 - i - idx3 + 1; ++j)
			right = (right + getDp(idx1 - i - 1, j, idx3 - 1)) % MOD;
		if (i == 0)
			left = 1;
		if (i == idx1 - 1)
			right = 1;
		ret = (ret + ((left * right) % MOD * nCr[idx1 - 1][i]) % MOD) % MOD;
	}
	
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> n >> l >> r;


	for (int i = 0; i < MAX_N; ++i) {
		nCr[i][0] = 1;
		nCr[i][1] = i;
	}
	for (int i = 1; i < MAX_N; ++i) 
		for (int j = 2; j <= i; ++j) 
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		

	memset(dp, -1, sizeof(dp));
	cout << getDp(n, l, r) << endl;
	
    return 0;
}