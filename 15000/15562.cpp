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
#define MAX_N 1000005
#define MOD 1'000'000'007

int n, m;
int ind[MAX_N];
int outd[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        ind[b]++;
        outd[a]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += max(0, ind[i] - outd[i]);
    cout << ans << endl;
    
    return 0;
}
