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

#define MAX_N 5

pii a, b, c;
double minValue = INF, maxValue = -INF;

bool isLinear() {
	ll value = (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
	return value == 0;
}

double dist(pii p1, pii p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> a >> b >> c;
	if (isLinear())
		cout << -1 << endl;
	else {
		minValue = min({ minValue, (dist(a, b) + dist(a, c)) * 2, (dist(a, b) + dist(b, c)) * 2, (dist(a, c) + dist(a, b)) * 2, (dist(a, c) + dist(c, b)) * 2, (dist(b, c) + dist(b, a)) * 2, (dist(b, c) + dist(c, a)) * 2 });
		maxValue = max({ maxValue, (dist(a, b) + dist(a, c)) * 2, (dist(a, b) + dist(b, c)) * 2, (dist(a, c) + dist(a, b)) * 2, (dist(a, c) + dist(c, b)) * 2, (dist(b, c) + dist(b, a)) * 2, (dist(b, c) + dist(c, a)) * 2 });

		cout.precision(11);
		cout << fixed << maxValue - minValue << endl;
	}

	return 0;
}
