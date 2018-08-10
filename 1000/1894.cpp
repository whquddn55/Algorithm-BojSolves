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

#define MAX_N 1000000

pair<double, double> a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cout.precision(3);
	cout << fixed;
	while (cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second) {
		if (a == c)
			swap(a, b);
		else if (b == d)
			swap(c, d);
		else if (a == d) {
			swap(a, b);
			swap(c, d);
		}
		cout << d.first - b.first + a.first << ' ' << d.second - b.second + a.second << endl;
	}

	return 0;
}
