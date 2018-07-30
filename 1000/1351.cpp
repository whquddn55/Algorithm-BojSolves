#include <bits/stdc++.h>
#include <unordered_map>
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

#define MAX_N 1000000

ll n;
int p, q;
map<ll, ll> m;

ll get(ll here) {
	ll& ret = m[here];
	if (ret != 0)
		return ret;

	return ret = get(here / p) + get(here / q);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> p >> q;
	m[0] = 1;

	cout << get(n) << endl;

	return 0;
}
