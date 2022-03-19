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
#define MAX_N 21
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

ll factorial[MAX_N];

ll nCr(int n, int r) {
    ll res = factorial[n];
    res /= factorial[r];
    return res / factorial[n - r];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    factorial[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
        factorial[i] = factorial[i - 1] * i;

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        ll ans = 0;
        int sign = 1;
        for (int i = n; i >= 0; --i) {
            ans += sign * factorial[i] * nCr(n, n - i);
            sign *= -1;
        }
        cout << ans << endl;
    }
    
    return 0;
}