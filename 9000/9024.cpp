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

#define all(x) (x.begin(), x.end())
#define INF (INT_MAX / 2)
#define MAX_N 1'000'005
#define MOD 1000000007

int n, k;
int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);

        int l = 0, r = n - 1;
        int ans = 0;
        int minV = INT_MAX;
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (abs(sum - k) < minV) {
                minV = abs(sum - k);
                ans = 1;
            } else if (abs(sum - k) == minV) {
                ++ans;
            }

            if (sum == k) {
                ++l;
                --r;
            }
            else if (sum > k)
                --r;
            else
                ++l;
        }

        cout << ans << endl;
    }

    return 0;
}
