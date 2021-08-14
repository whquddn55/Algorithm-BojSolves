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
#define MAX_N 105
#define MOD 1000000007

int n, m;
vector<pii> arr;
int dp[10005][MAX_N * 15];

int getDp(int i1, int i2) {
	if (i1 < 0)
		return -INF;
	if (i2 == arr.size())
		return 0;
	int& ret = dp[i1][i2];
	if (ret != -1)
		return ret;

	return ret = max(getDp(i1 - arr[i2].first, i2 + 1) + arr[i2].second, getDp(i1, i2 + 1));
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		pii a;
		int b;
		cin >> a >> b;
		int cnt = 1;
		while (true) {
			arr.emplace_back(a.first * cnt, a.second * cnt);

			b -= cnt;
			cnt <<= 1;
			if (b - cnt <= 0)
				break;
		}
		if (b)
			arr.emplace_back(a.first * b, a.second * b);
	}

	cout << getDp(m, 0) << endl;
	
	
	return 0;
}
