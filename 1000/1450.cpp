#include <bits/stdc++.h>
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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 35
#define MOD 1000000

int n, c;
int arr[MAX_N];
ll dp1[1 << (MAX_N / 2)];
ll dp2[1 << (MAX_N / 2)];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < (1 << (n / 2)); ++j)
            if (j & (1 << i)) {
                dp1[j] += arr[i];
            }
    }
    for (int i = 0; i < (n - (n / 2)); ++i) {
        for (int j = 0; j < (1 << (n - (n / 2))); ++j)
            if (j & (1 << i)) {
                dp2[j] += arr[i + n / 2];
            }
    }
    sort(dp2, dp2 + (1 << (n - (n / 2))));

    int ans = 0;
    for (int i = 0; i < (1 << (n / 2)); ++i) {
        ll remain = c - dp1[i];
        ans += upper_bound(dp2, dp2 + (1 << (n - (n / 2))), remain) - dp2;
    }
    cout << ans << endl;
    
    return 0;
}
