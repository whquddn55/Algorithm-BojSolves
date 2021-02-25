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

#define MAX_N 4000001
#define MOD 1000000007

int n;
bool isPrime[MAX_N];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= n; ++i)
		if (isPrime[i])
			for (int j = i * 2; j <= n; j += i)
				isPrime[j] = false;
	for (int i = 2; i <= n; ++i)
		if (isPrime[i])
			primes.emplace_back(i);
	
	int sum = 0;
	int result = 0;
	queue<int> inserted;
	for (auto prime : primes) {
		sum += prime;
		inserted.emplace(prime);
		while (sum > n) {
			sum -= inserted.front();
			inserted.pop();
		}
		if (sum == n)
			++result;
	}
	cout << result << endl;

	return 0;
}