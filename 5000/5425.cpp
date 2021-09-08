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
#define MOD 31991
#define MOD2 1000000009

int tc;
ll sum[16];

ll get(ll value) {
	if (value <= 0)
		return 0;

	int digits = 0;
	ll temp = value;
	while(temp) {
		temp /= 10;
		digits++;
	}

	temp = 1;
	for (int i = 0; i < digits - 1; ++i)
		temp *= 10;
	
	int mostDigit = value / temp;
	ll res = sum[digits - 1] * mostDigit;

	for (int i = 1; i < mostDigit; ++i)
		res += i * temp;

	res += mostDigit * (value % temp + 1);
	res += get(value % temp);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	ll v = 1;
	for (int i = 1; i < 16; ++i){
		sum[i] = 45LL * i * v;
		v *= 10;
	}

	cin >> tc;
	while(tc--) {
		ll a, b;
		cin >> a >> b;
		cout << get(b) - get(a - 1) << endl;
	}

	return 0;
}