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
#define MAX_N 1000000000005
#define MOD 1000003

ll n, a;

tuple<ll, ll, ll> egcd(ll a, ll b) {
	if (a == 0) return {b, 0, 1};
	auto [g, x, y] = egcd(b % a, a);
	return {g, y - (b / a) * x, x};
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> a;
	auto [g, x, y] = egcd(a, n);
	ll ans;
	if (g != 1) 
		ans = -1;
	else
		ans = (x % n + n) % n; 
	cout << n - a << ' ' << ans << endl;

	return 0;
}
