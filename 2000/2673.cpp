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
#define MAX_N 105
#define MOD 1000000007

int n;
bool arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int getDp(int idx1, int idx2) {
	if (idx1 >= idx2)
		return 0;
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = idx1; i < idx2; ++i) {
		ret = max(ret, getDp(idx1, i) + getDp(i, idx2) + arr[idx1][idx2]);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int f, t;
		cin >> f >> t;
		arr[f][t] = arr[t][f] = true;
	}

	memset(dp, -1, sizeof(dp));
	cout << getDp(1, 100) << endl;

	return 0;
}
