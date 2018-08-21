#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 100

string a, b, c;
int dp[MAX_N][MAX_N][MAX_N];

int getDp(int idx1, int idx2, int idx3) {
	if (idx1 == a.size() || idx2 == b.size() || idx3 == c.size())
		return 0;

	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	if (a[idx1] == b[idx2] && b[idx2] == c[idx3])
		return ret = getDp(idx1 + 1, idx2 + 1, idx3 + 1) + 1;
	return ret = max({ getDp(idx1 + 1, idx2, idx3), getDp(idx1, idx2 + 1, idx3), getDp(idx1, idx2, idx3 + 1) });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> a >> b >> c;
	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 0, 0) << endl;
	
	return 0;
}