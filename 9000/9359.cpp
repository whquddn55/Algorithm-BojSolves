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
#define MAX_N 33005
#define MOD 1000003

bool isPrime[MAX_N];
vector<int> primes;

ll get(ll here, ll value, ll sz, ll to, vector<ll>& factors) {
	if (here == factors.size()) {
		if (value == 1)
			return 0;
		return to / value * (sz % 2 ? 1 : -1);
	}

	return get(here + 1, value, sz, to, factors) + get(here + 1, value * factors[here], sz + 1, to, factors);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fill(isPrime, isPrime + MAX_N, 1);
	for (int i = 2; i < sqrt(MAX_N); ++i){
		if (isPrime[i])
			for (int j = i * 2; j < MAX_N; j += i)
				isPrime[j] = false;
	}

	for (int i = 2; i < MAX_N; ++i)
		if (isPrime[i]) { 
			primes.push_back(i);
		}

	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt){
		ll a, b, n;
		cin >> a >> b >> n;

		vector<ll> factors;
		for (auto p : primes) {
			if (n % p == 0) {
				factors.push_back(p);
				while(n % p == 0)
					n /= p;
			}
		}
		if (n != 1)
			factors.push_back(n);

		ll f = get(0, 1, 0, a - 1, factors), t = get(0, 1, 0, b, factors);
		cout << "Case #" << tt << ": "; 
		cout << (b - t) - (a - 1 - f) << endl;
	}

	return 0;
}
