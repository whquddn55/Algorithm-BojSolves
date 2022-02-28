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
#define MAX_N 1005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int a, b, c;

bool decide(double mid) {
    return a * mid + b * sin(mid) >= c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b >> c;
    
    double l = 0, r = 100'000;
    double mid;
    for (int i = 0; i < 50; ++i) {
    mid = (l + r) / 2;
        if (decide(mid))
            r = mid;
        else
            l = mid;
    }
    cout.precision(9);
    cout << fixed << mid << endl;
 
    return 0;
}
