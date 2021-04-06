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

#define MAX_N 15

ll a, b;

ll get(ll from, ll to) {
    if (from == 0) {
        if (to == 0)
            return 0;
        if (to == 1)
            return 1;

        ll mid = 1;
        int n = 0;
        while(mid <= to) {
            mid <<= 1;
            ++n;
        }
        n -= 2;
        if (to == mid - 1) {
            ll v1 = 1, v2 = 3;
            ll result = 1;
            for (int i = 0; i <= n; ++i) {
                result += v1 * v2;
                v1 <<= 1;
                v2 += 1;
            }
            return result;
        }
        else {
            mid = mid / 2 - 1;
            return get(from, mid) + get(mid + 1, to);
        }
    }
    else {
        return (to - from + 1) + get(0, to - from);
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> a >> b;

    cout << get(0, b) - get(0, a - 1) << endl;

	return 0;
}
