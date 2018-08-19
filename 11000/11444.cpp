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

#define MAX_N 1000001

ll n;

struct Matrix {
	ll a, b, c, d;
	Matrix(int a, int b, int c, int d)
		: a(a), b(b), c(c), d(d) { }

	void operator*=(const Matrix o) {
		ll ta = a;
		ll tc = c;
		a = a * o.a + b * o.c;
		b = ta * o.b + b * o.d;
		c = c * o.a + d * o.c;
		d = tc * o.b + d * o.d;

		a %= 1000000007;
		b %= 1000000007;
		c %= 1000000007;
		d %= 1000000007;
 	}

	void operator^=(ll e) {
		Matrix m(1, 0, 0, 1);
		while (e) {
			if (e % 2)
				m *= *this;

			e /= 2;
			*this *= *this;
		}
		*this = m;
	}

	void print() {
		cout << pair<pii, pii>(pii((*this).a, (*this).b), pii((*this).c, (*this).d)) << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	Matrix m(2, 1, 1, 1);

	m ^= (n - 1) / 2;

	if (n % 2)
		cout << m.a << endl;
	else
		cout << (m.a + m.b) % 1000000007 << endl;
	
	return 0;
}