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

#define INF (LLONG_MAX / 2)

#define MAX_N 1000001

ll minValue, maxValue;
bool isnPrime[MAX_N];
vector<int> primes;

bool ans[MAX_N];
int ret = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> minValue >> maxValue;
	for (int i = 2; i <= sqrt(MAX_N); i++) {
		if (!isnPrime[i])
			for (int j = i * 2; j < MAX_N; j += i)
				isnPrime[j] = true;
	}
	for (int i = 2; i < MAX_N; i++)
		if (!isnPrime[i])
			primes.emplace_back(i);
	
	for (ll e : primes) {
		ll t = (minValue + (e * e - 1)) / (e * e) * (e * e);
		
		while (t <= maxValue) {
			ans[t - minValue] = true;
			t += e * e;
		}
	}
	for (int i = 0; i <= maxValue - minValue; i++)
		if (!ans[i]) {
			/*cout << i + minValue << endl;*/
			ret++;
		}
	cout << ret << endl;


	return 0;
}