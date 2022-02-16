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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int s, p;
    cin >> s >> p;

    if (s == p) {
        cout << 1 << endl;
        return 0;
    }
    int ans = -1;
    for (int i = 2; i <= s + 20; ++i) {
        if (p <= pow((s * 1.0 / i), i)){
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
