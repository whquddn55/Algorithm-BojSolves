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
#define MAX_N 1005
#define MOD 1000000007

int n;
int dp[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;

	dp[0] = dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		set<int> temp;
		for (int j = 0; j <= i - 2; ++j)
			temp.insert(dp[j]^dp[i - j - 2]);
		int mex = 0;
		for (int e : temp) {
			if (mex != e) {
				dp[i] = mex;
				break;
			}
			++mex;
		}
		if (mex == temp.size())
			dp[i] = mex;
	}

	cout << (dp[n] ? 1 : 2) << endl;

	return 0;
}
