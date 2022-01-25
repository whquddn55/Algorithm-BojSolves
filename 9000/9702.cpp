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
#define MAX_N 505
#define MOD 1'000'000'007

int tc;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> tc;
    for (int ttcc = 1; ttcc <= tc; ++ttcc) {
        cout << "Case #" << ttcc << ": ";

        int n;
        int arr[MAX_N];
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> lis;
            for (int j = i; j < n; ++j) {
                auto it = lower_bound(all(lis), arr[j]);
                if (it == lis.end())
                    lis.emplace_back(arr[j]);
                else
                    *it = arr[j];
                ans += lis.size();
            }
        }
        cout << ans << endl;
    }

    return 0;
}
