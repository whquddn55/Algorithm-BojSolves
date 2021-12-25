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
#define MAX_N 105
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N];
int ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> arr[i];

    for (int i = 0; i < m; ++i) {
        int cnt = n;
        for (int j = 1; j <= n; ++j) {
            int t;
            cin >> t;
            if (t == arr[i]) {
                ++ans[j];
                --cnt;
            }
        }
        ans[arr[i]] += cnt;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    
    return 0;
}
