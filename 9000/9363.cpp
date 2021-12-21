#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 110005
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N], brr[MAX_N];
bool isPrime[MAX_N * 10];
int aCnt[MAX_N];
int bCnt[MAX_N];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= sqrt(MAX_N * 10); ++i)
		if (isPrime[i])
			for (int j = i + i; j < MAX_N * 10; j += i)
				isPrime[j] = false;

	for (int i = 2; i < MAX_N * 10; ++i)
		if (isPrime[i])
			primes.push_back(i);


	int tc;
	cin >> tc;
	for (int ttcc = 1; ttcc <= tc; ++ttcc){
		cout << "Case #" << ttcc << ": ";
		memset(aCnt, 0, sizeof(aCnt));
		memset(bCnt, 0, sizeof(bCnt));
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for (int i = 0; i < m; ++i)
			cin >> brr[i];

		for (int i = 0; i < n; ++i) {
			int temp = arr[i];
			for (int j = 0; j < primes.size(); ++j) {
				if (isPrime[temp])
					break;
				while ((temp % primes[j])== 0) {
					temp /= primes[j];
					aCnt[j]++;
				}
			}
			if (temp != 1) {
				aCnt[lower_bound(all(primes), temp) - primes.begin()]++;
			}
		}	

		for (int i = 0; i < m; ++i) {
			int temp = brr[i];
			for (int j = 0; j < primes.size(); ++j) {
				if (isPrime[temp])
					break;
				while ((temp % primes[j]) == 0) {
					temp /= primes[j];
					bCnt[j]++;
				}
			}
			if (temp != 1) {
				bCnt[lower_bound(all(primes), temp) - primes.begin()]++;
			}
		}	

		ll a = 1, b = 1;
		for (int i = 0; i < primes.size(); ++i) {
			ll cnt = min(aCnt[i], bCnt[i]);
			if (aCnt[i] > bCnt[i])
				a *= primes[i] * (aCnt[i] - bCnt[i]);
			else if (aCnt[i] < bCnt[i])
				b *= primes[i] * (bCnt[i] - aCnt[i]);
		}

		cout << a << " / " <<b << endl;
	}
	
	return 0;
}