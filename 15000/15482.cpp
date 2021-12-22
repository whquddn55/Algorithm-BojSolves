#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 3005
#define MOD 1'000'000'007

string a, b;
int dp[MAX_N][MAX_N];
int getDp(int i1, int i2) {
	if (i1 == a.size() || i2 == b.size())
		return 0;
	int& ret = dp[i1][i2];
	if (ret != -1)
		return ret;

	if (a.substr(i1, 3) == b.substr(i2, 3))
		return ret = getDp(i1 + 3, i2 + 3) + 1;
	return ret = max(getDp(i1 + 3, i2), getDp(i1, i2 + 3));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 0) << endl;
	
	return 0;
}