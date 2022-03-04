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
#define MAX_N 100005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n, k;
string a, b;
set<ll> arr;

const int p1 = 53;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    cin >> a >> b;

    ll h[2] = {a[0], a[0]};
    ll powered[2] = {1, 1};
    for (int i = 1; i < k; ++i) {
        h[0] = (h[0] * p1 + a[i]) % MOD;
        h[1] = (h[1] * p1 + a[i]) % MOD2;
        powered[0] = powered[0] * p1 % MOD;
        powered[1] = powered[1] * p1 % MOD2;
    }

    arr.insert(h[0] << 32 | h[1]);
    
    for (int i = k; i < n; ++i) {
        h[0] = (h[0] - a[i - k] * powered[0] % MOD + MOD) % MOD;
        h[0] = (h[0] * p1 % MOD + a[i]) % MOD;
        h[1] = (h[1] - a[i - k] * powered[1] % MOD2 + MOD2) % MOD2;
        h[1] = (h[1] * p1 % MOD2 + a[i]) % MOD2;

        arr.insert(h[0] << 32 | h[1]);
    }

    int ans = 0;
    h[0] = b[0]; h[1] = b[0];
    for (int i = 1; i < k; ++i) {
        h[0] = (h[0] * p1 + b[i]) % MOD;
        h[1] = (h[1] * p1 + b[i]) % MOD2;
    }

    bool res = arr.find(h[0] << 32 | h[1]) != arr.end();
    if (res) {
        ++ans;
        arr.erase(h[0] << 32 | h[1]);
    }
    
    for (int i = k; i < n; ++i) {
        h[0] = (h[0] - b[i - k] * powered[0] % MOD + MOD) % MOD;
        h[0] = (h[0] * p1 % MOD + b[i]) % MOD;
        h[1] = (h[1] - b[i - k] * powered[1] % MOD2 + MOD2) % MOD2;
        h[1] = (h[1] * p1 % MOD2 + b[i]) % MOD2;
        
        bool res = arr.find(h[0] << 32 | h[1]) != arr.end();
        if (res) {
            ++ans;
            arr.erase(h[0] << 32 | h[1]);
        }
    }

    cout << ans << endl;

    return 0;
}