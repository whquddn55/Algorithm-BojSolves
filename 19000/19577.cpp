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

#define MAX_N 35000

bool prime[MAX_N];
vector<int> primes;

int phi(int x) {
	int result = x;
	for (auto p : primes)
		if (x % p == 0)
			result = result * (p - 1) / p;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < MAX_N; i++) 
		if (prime[i]) {
			for (int j = i * 2; j < MAX_N; j += i)
				prime[j] = false;
			primes.emplace_back(i);
		}

	int result = -1;
	for (int i = 1; i * i <= n; i++) 
		if (n % i == 0) {
			if (i * phi(i) == n) {
				result = i;
				break;
			}
			else if (n / i * phi(n / i) == n) {
				result = n / i;
				break;
			}
		}
	cout << result << endl;

	return 0;
}