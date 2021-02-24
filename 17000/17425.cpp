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

#define MAX_N 1000000
#define MOD 1000000007

int n;
bool isPrime[MAX_N + 1];
vector<int> primes;

ll gx[MAX_N + 1];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= MAX_N; ++i)
		if (isPrime[i]) 
			for (int j = i * 2; j <= MAX_N; j += i)
				isPrime[j] = false;
	for (int i = 2; i <= MAX_N; ++i)
		if (isPrime[i])
			primes.emplace_back(i);

	isPrime[1] = true;
	for (int i = 1; i <= MAX_N; ++i) {
		vector<pii> factors;
		int k = i;

		int to = lower_bound(primes.begin(), primes.end(), sqrt(i) + 1) - primes.begin();
		while (!isPrime[k]) {
			for (int j = 0; j < to; ++j) {
				int prime = primes[j];
				if (k % prime == 0) {
					k /= prime;
					bool check = false;
					for (auto& factor : factors) 
						if (factor.first == prime) {
							factor.second *= prime;
							check = true;
							break;
						}
					if (!check)
						factors.emplace_back(pii(prime, prime));
					break;
				}
			}
		}
		if (k != 1) {
			bool check = false;
			for (auto& factor : factors)
				if (factor.first == k) {
					factor.second *= k;
					check = true;
					break;
				}
			if (!check)
				factors.emplace_back(pii(k, k));
		}

		int fx = 1;
		for (auto& factor : factors) {
			int value = 0;
			while (factor.second) {
				value += factor.second;
				factor.second /= factor.first;
			}
			fx *= value;
		}
		gx[i] = gx[i - 1] + fx;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << gx[n] << endl;
	}

	
	

	return 0;
}