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
#define MOD 1000003

int n;
int arr[MAX_N];

bool isPrime[2000005];
vector<int> primes;

int cnt[2000005];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int maxValue = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		maxValue = max(maxValue, arr[i]);
	}

	const int maxV = maxValue * 2 / n;
	for (int i = 2; i <= sqrt(maxV); ++i)
		if (!isPrime[i])
			for (int j = i * 2; j <= maxV; j += i)
				isPrime[j] = true;
	for (int i = 2; i <= maxV; ++i)
		if (!isPrime[i])
			primes.push_back(i);

	int ans = 0;
	for(auto p : primes) {
		for (int i = 0; i < n; ++i) 
			ans = max(ans, ++cnt[arr[i] % p]);
		for (int i = 0; i < n; ++i)
			--cnt[arr[i] % p];
	}
	cout << ans << endl;
	

	return 0;
}
