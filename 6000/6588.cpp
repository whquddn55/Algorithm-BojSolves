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
#define MOD 1000000007

int n;
bool isPrime[MAX_N];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (ll i = 2; i * i <= MAX_N; ++i)
		if (isPrime[i]) 
			for (ll j = i * 2; j < MAX_N; j += i)
				isPrime[j] = false;
	for (int i = 0; i < MAX_N; ++i)
		if (isPrime[i]) 
			primes.emplace_back(i);
	while (true) {
		cin >> n;
		if (!n)
			break;
		
		for (auto it = primes.begin(); it != primes.end(); ++it) {
			if (*it >= n)
				break;
			if (isPrime[n - *it]) {
				cout << n << " = " << *it << " + " << n - *it << endl;
				break;
			}
		}
	}

	return 0;
}