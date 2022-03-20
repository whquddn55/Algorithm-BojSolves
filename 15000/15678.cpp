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

int n, d;
int arr[MAX_N];
ll res[MAX_N];
multiset<ll> dp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    ll ans = -INF;
    for (int i = 0; i < n; ++i) {
        ll value = max(0LL, (dp.empty() ? 0 : *dp.rbegin())) + arr[i];
        ans = max(ans, value);
        dp.insert(value);
        res[i] = value;
        if (dp.size() > d) {
            dp.erase(dp.find(res[i - d]));
        }
    }
    cout << ans << endl;
    
    return 0;
}