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
#define MOD2 1000000009

int n;
int arr[MAX_N];
pii dp[2][MAX_N][MAX_N];

pii getDp(int i1, int i2, int i3) {
	if (i2 > i3)
		return {0, 0};
	pii& ret = dp[i1][i2][i3];
	if (ret.first != -1)
		return ret;
	
	pii l = getDp(!i1, i2 + 1, i3);
	pii r = getDp(!i1, i2, i3 - 1);
	if (!i1) {
		if (l.first + arr[i2] < r.first + arr[i3]) 
			ret = {r.first + arr[i3], r.second};
		else
			ret = {l.first + arr[i2], l.second};
	}
	else {
		if (l.second + arr[i2] < r.second + arr[i3]) 
			ret = {r.first, r.second + arr[i3]};
		else
			ret = {l.first, l.second + arr[i2]};
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		cout << getDp(0, 0, n - 1).first << endl;
	}
	
	return 0;
}
