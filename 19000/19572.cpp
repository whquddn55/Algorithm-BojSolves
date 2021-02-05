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

#define MAX_N 505


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;

	double a = d1 + d2 - d3;
	a /= 2;
	double b = d1 - d2 + d3;
	b /= 2;
	double c = -d1 + d2 + d3;
	c /= 2;

	cout.precision(1);
	cout << fixed;
	if (a <= 0 || b <= 0 || c <= 0)
		cout << -1 << endl;
	else
		cout << 1 << endl << a << ' ' << b << ' ' << c << endl;
	
	return 0;
}