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
#define MAX_N 13
#define MOD 1'000'000'007

ll n;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    ll l = 1;
    ll temp = n;
    while(temp) {
        if (temp % 10)
            l = lcm(l, temp % 10);
        temp /= 10;
    }

    ll ans = -1;
    for (int i = 1; i <= 1000000; i *= 10) {
        for (int j = 0; j < i; ++j) {
            ll value = n * i + j;
            if (value % l == 0)  {
                ans = value;
                break;
            }
        }
        if (ans != -1)
            break;
    }
    cout << ans << endl;

    return 0;
}
