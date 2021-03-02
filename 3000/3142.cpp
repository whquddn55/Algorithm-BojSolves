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

#define MAX_N 500005
#define MOD 1000000007

int n;
bool isPrime[MAX_N * 2];
vector<int> primes;
int cnt[80000];
int oddCnt;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fill(isPrime, isPrime + MAX_N * 2, true);
	for (int i = 2; i * i < MAX_N * 2; ++i)
		if (isPrime[i]) 
			for (int j = i * 2; j < MAX_N * 2; j += i)
				isPrime[j] = false;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAX_N * 2; ++i)
		if (isPrime[i])
			primes.emplace_back(i);
	
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		int t = num;
		
		for (int i = 0; i < primes.size(); ++i) {
			int prime = primes[i];
			if (t == 1)
				break;
			if (prime * prime > t) {
				if (isPrime[t]) {
					int index = lower_bound(primes.begin(), primes.end(), t) - primes.begin();
					cnt[index]++;
					if (cnt[index] % 2 == 0)
						oddCnt--;
					else
						oddCnt++;
				}
				break;
			}
			if (t % prime == 0) {
				int x = 0;
				while (t % prime == 0) {
					t /= prime;
					x++;
				}
				cnt[i] += x;

				
				if (cnt[i] % 2 == 0 && x % 2 == 1)
					oddCnt--;
				else if (cnt[i] % 2 == 1 && x % 2 == 1)
					oddCnt++;
			}
		}
		if (oddCnt == 0)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	

	return 0;
}