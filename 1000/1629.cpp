#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 2000

ll a, b, c;

ll get(ll a, ll b) {
	if (a == 0)
		return 0;
	ll ans = 1;
	while (b) {
		if (b % 2)
			ans *= a;
		ans %= c;
		b /= 2;
		a *= a;
		a %= c;
	}
	return ans % c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> a >> b >> c;
	cout << get(a, b) << endl;

	return 0;
}
