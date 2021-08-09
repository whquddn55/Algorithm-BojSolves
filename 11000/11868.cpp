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

	ll grundy = 0;
	for (int i = 0; i < n; ++i)  {
		int p;
		cin >> p;
		grundy ^= p;
	}

	cout << (grundy ? "koosaga" : "cubelover") << endl;

	return 0;
}
