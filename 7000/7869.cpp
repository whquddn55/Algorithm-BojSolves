#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 2005
#define MOD 1'000'000'007

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if (r1 > r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    double d = sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));

    cout.precision(3);
    cout << fixed;
    if (d >= r1 + r2)
        cout << 0.000 << endl;
    else if (d + r1 <= r2) {
        cout << acos(-1) * r1 * r1 << endl;
    }
    else {
        double d1 = ((pow(r1, 2) - pow(r2, 2)) / d + d) / 2;
        double d2 = d - d1;
        double theta1 = acos(d1 / r1) * 2;
        double theta2 = acos(d2 / r2) * 2;
        double ans = r1 * r1 * theta1 / 2 + r2 * r2 * theta2 / 2;
        ans -= r1 * r1 * sin(theta1) / 2 + r2 * r2 * sin(theta2) / 2;
        cout << ans << endl;
    }
    
    return 0;
}
