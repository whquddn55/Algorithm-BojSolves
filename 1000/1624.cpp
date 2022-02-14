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

int n;
pii range[MAX_N];
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < MAX_N; ++i) {
        range[i] = {INF, -INF};
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        t += 1000;
        range[t].first = min(range[t].first, i);
        range[t].second = max(range[t].second, i);
    }
    
    for (int i = 0; i < MAX_N; ++i) {
        if (range[i] != pii(INF, -INF))
            arr.emplace_back(i);
    }

    int ans = 1;
    int prv = INF;
    bool isDescent = true;
    for (auto value : arr) {
        if (isDescent) {
            if (prv <= range[value].second) {
                isDescent = false;
                prv = range[value].second;
            } else {
                prv = range[value].first;
            }
        } else {
            if (prv <= range[value].first) {
                prv = range[value].second;
            } else {
                ans += 1;
                isDescent = true;
                prv = range[value].first;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
