#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 1000001

int n;
double dp[MAX_N];

double getDp(int idx1) {
	if (idx1 >= n)
		return 0.0;

	double& ret = dp[idx1];
	if (ret >= -0.5)
		return ret;

	ret = 0.0;
	for (int i = 1; i <= 6; i++)
		ret += (getDp(idx1 + i) + 1) /6.0;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	fill_n(dp, MAX_N, -1.0);
	//memset(dp, -1.0, sizeof(dp));

	cout.precision(11);
	cout << fixed << getDp(0) << endl;
	
	return 0;
}