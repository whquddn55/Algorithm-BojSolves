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

#define MAX_N 5005

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
	}
	
	return 0;
}