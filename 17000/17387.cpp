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

#define MAX_N 3005

int n;

int ccw(pii& a, pii& b, pii& c) {
    ll value = (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
    if (value < 0)
        return -1;
    else if (value > 0)
        return 1;
    else
        return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    pair<pii, pii> a, b;
    cin >> a >> b;

    int result1 = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    int result2 = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);

    bool check = false;
    if (result1 <= 0 && result2 <= 0) {
        if ((result1 == 0 && result2 == 0)) {
            if ((a.second.first - a.first.first) * (b.second.second - b.first.second) == (a.second.second - a.first.second) * (b.second.first - b.first.first)) {
                if ((((a.first.first <= b.second.first && b.second.first <= a.second.first) || (a.first.first <= b.first.first && b.first.first <= a.second.first) || (a.second.first <= b.second.first && b.second.first <= a.first.first) || (a.second.first <= b.first.first && b.first.first <= a.first.first)) && 
                    ((a.first.second <= b.second.second && b.second.second <= a.second.second) || (a.first.second <= b.first.second && b.first.second <= a.second.second) || (a.second.second <= b.second.second && b.second.second <= a.first.second) || (a.second.second <= b.first.second && b.first.second <= a.first.second))) ||
                    (((b.first.first <= a.second.first && a.second.first <= b.second.first) || (b.first.first <= a.first.first && a.first.first <= b.second.first) || (b.second.first <= a.second.first && a.second.first <= b.first.first) || (b.second.first <= a.first.first && a.first.first <= b.first.first)) && 
                    ((b.first.second <= a.second.second && a.second.second <= b.second.second) || (b.first.second <= a.first.second && a.first.second <= b.second.second) || (b.second.second <= a.second.second && a.second.second <= b.first.second) || (b.second.second <= a.first.second && a.first.second <= b.first.second))) ) {
                        check = true;
                    }
            }
            else
                check = true;
        }
        else
            check = true;
    }
    cout << check << endl;

	return 0;
}
