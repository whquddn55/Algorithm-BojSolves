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

	while(cin >> p1 >> p2 >> p3 >> p4) {
		int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
		int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
		int ret = 0;
		if (r1 == 0 && r2 == 0) {
            ret = 0;
					}
		else  {
			ret = (r1 <= 0 && r2 <= 0);
		}
		cout << ret << endl;
	}
	
	return 0;
}
