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
#define MAX_N 100'000'001
#define MOD 1'000'000'007

int n;
bitset<MAX_N / 2> isPrime;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    ll res = 1;
    ll m = (1LL << 32);

    for (int i = 3; i <= n; i += 2) {
        if (!isPrime[i / 2]) {
            for (ll j = (ll)i * i; j <= n; j += 2*i)
                isPrime[j / 2] = true;
            ll temp = 1;
            while(temp * i <= n) temp *= i;
            res = (res * temp) % m;
        }
    }
    ll temp = 1;
    while(temp * 2 <= n) temp *= 2;
    res = (res * temp) % m;

    cout << res << endl;

    return 0;
}
