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
#define MOD2 1'000'000'009

int n;
int arr[MAX_N];

ll get(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) / 2;

    ll ans = 0;
    ans += get(l, mid);
    ans += get(mid + 1, r);
    
    int temp[r - l + 1];
    int tempIndex = 0;
    int pl = l, pr = mid + 1;
    while (pl <= mid && pr <= r) {
        if (arr[pl] < arr[pr]) {
            temp[tempIndex] = arr[pl];
            ++pl;
        } else {
            temp[tempIndex] = arr[pr];
            ++pr;
            ans += (mid + 1 - pl);
        }
        ++tempIndex;
    }
    while (pl <= mid) {
        temp[tempIndex] = arr[pl];
        ++pl;
        ++tempIndex;
    }
    while (pr <= r) {
        temp[tempIndex] = arr[pr];
        ++pr;
        ++tempIndex;
        ans += (mid + 1 - pl);
    }
    for (int i = l; i <= r; ++i)
        arr[i] = temp[i - l];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << get(0, n - 1) << endl;
    
    return 0;
}
