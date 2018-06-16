#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator<<(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 10000001LL

ll a, b;
bool isPrime[MAX_N];

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> a >> b;

	fill_n(isPrime, MAX_N, true);
	isPrime[1] = isPrime[0] = false;

	ll sqrta = sqrt(a);
	ll sqrtb = sqrt(b);
	for (ll i = 2; i <= sqrtb; ++i)
		if (isPrime[i])
			for (ll j = i + i; j <= sqrtb; j += i)
				isPrime[j] = false;

	for (ll i = 2; i <= sqrtb; ++i)
		if (isPrime[i])
			for (ll j = i * i; j <= b; j *= i) {
				if (j >= a)
					ans++;
				if ((j >= MAX_N * MAX_N / i))
					break;
			}
		
	cout << ans << endl;

	return 0;
}