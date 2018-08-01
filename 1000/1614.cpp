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

#define MAX_N 5000

int n, m;
ll ans;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	if (n != 5 && n != 1) {
		ans += 8LL * (m / 2);
		if (m % 2) {
			ans += 5;
			ans += (4 - n);
		}
		else
			ans += n - 1;
	}
	else {
		ans += 8LL * m;
		if (n == 5)
			ans += 4;
	}
	cout << ans << endl;

	return 0;
}