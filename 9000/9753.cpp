#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)

#define MAX_N 100005

int n;
bool isPrime[MAX_N];
vector<int> primes;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fill(isPrime, isPrime + MAX_N, true);

	for (ll i = 2; i * i < MAX_N; i++)
		if (isPrime[i])
			for (int j = i * 2; j < MAX_N; j += i)
				isPrime[j] = false;

	for (int i = 2; i < MAX_N; i++)
		if (isPrime[i])
			primes.push_back(i);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		
		int ans = INF;
		for (int p : primes) {
			int d = (n + p - 1) / p;
			auto it = lower_bound(primes.begin(), primes.end(), d);
			if (*it == p)
				++it;
			ans = min(ans, p * (*it));
		}
		cout << ans << endl;

	}
	

	return 0;
}