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
#define MAX_N 10005
#define MOD 1000000007

pii p1, p2, p3, p4;

int ccw(pll a, pll b, pll c) {
	ll ret = (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);
	return ret ? ret / abs(ret) : ret;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cout.precision(17);
	cout << fixed;

	cin >> p1 >> p2 >> p3 >> p4;

	int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	int ret = 0;
	if (r1 == 0 && r2 == 0) {
		if (p1 > p2)
			swap(p1, p2);
		if (p3 > p4)
			swap(p3, p4);
		ret = !(p2 < p3 || p1 > p4);
	}
	else  {
		ret = (r1 <= 0 && r2 <= 0);
	}
	cout << ret << endl;
	if (ret) {
		if (p1.first == p2.first) {
			if (p3.first == p4.first) {
				if (p2 == p3)
					cout << p2 << endl;
				else if (p1 == p4)
					cout << p1 << endl;
			}
			else {
				double c = (double)(p3.second - p4.second) / (p3.first - p4.first);
				double d = p3.second - c * p3.first;
				cout << pair<double, double>(p1.first, p1.first * c + d) << endl;
			}
		}
		else if (p3.first == p4.first) {
			double a = (double)(p1.second - p2.second) / (p1.first - p2.first);
			double b = p1.second - a * p1.first;
			cout << pair<double, double>(p3.first, p3.first * a + b) << endl;
		}
		else {
			double a = (double)(p1.second - p2.second) / (p1.first - p2.first);
			double b = p1.second - a * p1.first;
			double c = (double)(p3.second - p4.second) / (p3.first - p4.first);
			double d = p3.second - c * p3.first;

			if (a == c) {
				if (p2 == p3)
					cout << p2 << endl;
				else if (p1 == p4)
					cout << p1 << endl;
			}
			else {
				cout << pair<double, double>((d - b) / (a - c), (d - b) / (a - c) * c + d) << endl;
			}
		}
	}
	
	return 0;
}
