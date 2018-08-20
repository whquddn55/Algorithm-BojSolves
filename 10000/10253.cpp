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

pll value;

ll euclid(ll a, ll b) {
	if (b == 0)
		return a;
	return euclid(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> value;
		while (true) {
			if (value.first == 1) {
				cout << value.second << endl;
				break;
			}
			ll t = value.second / value.first + ((value.second % value.first) != 0);
			ll gcd = euclid(value.second, t);
			value.first *= t / gcd;
			value.first -= value.second / gcd;
			value.second *= t / gcd;

			gcd = euclid(value.first, value.second);
			value.first /= gcd;
			value.second /= gcd;
		}
	}
	
	return 0;
}