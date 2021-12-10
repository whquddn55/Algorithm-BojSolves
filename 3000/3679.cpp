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
pii arr[MAX_N];
int idx[MAX_N];

int ccw(pll a, pll b, pll c) { // 1: 반시계, -1 : 시계
    ll ret = (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);
    return ret ? ret / abs(ret) : ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        for (int i = 0; i < MAX_N; ++i)
            idx[i] = i;

        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        sort(idx, idx + n, [](int i1, int i2)-> bool {
            return arr[i1] < arr[i2];
        });
        sort(idx + 1, idx + n, [](int i1, int i2)-> bool {
            pii& a = arr[i1];
            pii& b = arr[i2];
            int v = ccw(arr[idx[0]], a, b);
            if (v)
                return v == 1;
            return a < b;
        });
        
        int cnt = 0;
        for (int i = n - 1; i >= 1; --i)
            if (ccw(arr[idx[0]], arr[idx[n - 1]], arr[idx[i]]) == 0)
                ++cnt;
            else
                break;

        reverse(idx + n - cnt, idx + n);

        for (int i = 0; i < n; ++i)
            cout << idx[i] << ' ';
        cout << endl;
    }
    
    return 0;
}
