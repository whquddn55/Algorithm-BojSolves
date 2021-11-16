#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_N 2005
#define INF (INT_MAX / 2)
#define endl '\n'

ll n, a, b, c, d;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b >> c >> d;

    if (b * c < a * d) {
        swap(a, c);
        swap(b, d);
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < c; ++i) {
        ll remain = n - a * i;
        remain = max(0ll, remain);
        ans = min(ans, i * b + (remain / c + ((remain % c) ? 1 : 0)) * d);
    }
    cout << ans << endl;

    return 0;
}
