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
#define MAX_N 1000000005
#define MOD 1000003

ll n;
bool isPrime[32000];
vector<int> primes;

ll pi(ll v) {
	ll ans = v;
	for (auto p : primes)
		if (v % p == 0) {
			ans = ans / p * (p - 1);
			while(v % p == 0)
				v /= p;
		}
	if (v != 1)
		ans = ans / v * (v - 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fill(isPrime, isPrime + 32000, 1);
	for (int i = 2; i < sqrt(32000); ++i){
		if (isPrime[i])
			for (int j = i * 2; j < 32000; j += i)
				isPrime[j] = false;
	}

	for (int i = 2; i < 32000; ++i)
		if (isPrime[i]) { 
			primes.push_back(i);
		}

	while(true) {
		cin >> n;
		if (!n)
			break;
		cout << pi(n) << endl;
	}

	return 0;
}
