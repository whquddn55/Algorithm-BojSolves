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
#define MAX_N 200005
#define MOD 1'000'000'007

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cout << pii(50, 50) << endl;
    for (int i = 50; i >= 1; --i) {
        cout << pii(i, i % 50 + 1) << ' ';
        if (i == 49)
            cout << -1 << endl;
        else if (i >= 37)
            cout << 1 << endl;
        else
            cout << (i % 3 == 1 ? 1 : -1) << endl;
    }

    return 0;
}
