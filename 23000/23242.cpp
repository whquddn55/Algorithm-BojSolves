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
#define MAX_N 4005
#define MOD 1000000007

int b, n;
int arr[MAX_N];
double dp[33][MAX_N];

double getDp(int i1, int i2) {
	if (i1 == b || i2 == n) {
		if (i2 == n)
			return 0;
		return INF;
	}

	double& ret = dp[i1][i2];
	if (ret >= 0)
		return ret;

	ret = INF;

	ll sum = 0;
	ll ssum = 0;
	int cnt = 0;
	for (int i = i2; i < n; ++i) {
		++cnt;
		sum += arr[i];
		ssum += arr[i] * arr[i];
		ret = min(ret, getDp(i1 + 1, i + 1) + ssum - (sum * sum) / (double)cnt);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> b >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int j = 0; j < MAX_N; ++j)
		for (int i = 0; i < 33; ++i)
			dp[i][j] = -1.0;

	cout.precision(10);
	cout << fixed;
	cout << getDp(0, 0) << endl;
	
	return 0;
}