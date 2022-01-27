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
#define MAX_N 65
#define MOD 1'000'000'007

ll dp[MAX_N][MAX_N];

ll getDp(int i1, int i2) {
    if (i1 == 0 && i2 == 0)
        return 1;

    ll& ret = dp[i1][i2];
    if (ret != -1)
        return ret;

    ret = 0;
    if (i1 != 0) {
        ret += getDp(i1 - 1, i2 + 1);
    }
    if (i2 != 0) {
        ret += getDp(i1, i2 - 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        
        memset(dp, -1 ,sizeof(dp));
        cout << getDp(n, 0) << endl;
    }

    return 0;
}
