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

#define MAX_N 11

int n, k;
ll a = 1, b = 1;

ll fastPow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b % 2)
			ret = (ret * a) % 1000000007;
		a = (a * a) % 1000000007;
		b /= 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	for (int i = n; i > n - k; i--)
		a = (a * i) % 1000000007;
	for (int i = 1; i <= k; i++)
		b = (b * i) % 1000000007;

	cout << (a * fastPow(b, 1000000005)) % 1000000007 << endl;

	return 0;
}