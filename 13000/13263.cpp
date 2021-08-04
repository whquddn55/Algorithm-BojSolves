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
#define MAX_N 100005
#define MOD 1000000007

int n;
ll a[MAX_N];
ll b[MAX_N];
ll dp[MAX_N];
vector<pll> st;

double getCross(int i1, int i2) {
	ll p1 = b[i1], p2 = b[i2];
	ll c1 = dp[i1], c2 = dp[i2];
	return (double)(c2 - c1) / (p1 - p2);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int pt = 0;
	dp[0] = 0;
	st.emplace_back(0, 0);
	for (int i = 1; i < n; ++i) {
		int j = (--lower_bound(st.begin(), st.end(), pll(a[i], 0)))->second;
		dp[i] = dp[j] + b[j] * a[i];

		while(st.size() > 1 && st.back().first > getCross(st.back().second, i))
			st.pop_back();
		st.emplace_back(getCross(st.back().second, i), i);
		if (pt >= st.size())
			pt = st.size() - 1;
	}

	cout << dp[n - 1] << endl;

	return 0;
}
