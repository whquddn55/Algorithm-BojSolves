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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 5000

double a, b, c;

int d(double area) {
	double t1 = 2 * area / a;
	double t2 = 2 * area / b;
	double t3 = 2 * area / c;

	double s = (t1 + t2 + t3) / 2;
	double t = sqrt(s * (s - t1) * (s - t2) * (s - t3));
	if (abs(t - area) <= 1e-10)
		return 2;
	if (t > area)
		return 1;
	return 0;
}

double pSearch() {
	double l = 0, r = 5000000;
	double ans;
	while(l < r) {
		double mid = (l + r) / 2;
		int ret = d(mid);
		if (ret == 2) {
			ans = mid;
			break;
		}
		if (ret) 
			r = mid;
		else
			l = mid;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> a >> b >> c;
	
	cout.precision(10);
	cout << fixed;
	cout << pSearch() << endl;
	
	return 0;
}