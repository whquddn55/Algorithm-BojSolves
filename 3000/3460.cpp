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
#define MAX_N 55
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        int cnt = 0;
        while(n) {
            if (n % 2 == 1) cout << cnt << ' ';
            ++cnt;
            n /= 2;
        }
        cout << endl;
    }
    
    return 0;
}