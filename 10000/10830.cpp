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
#define MAX_N 5
#define MOD 1'000'000'007

ll n, b;
ll arr[MAX_N][MAX_N];

void mul(ll a[MAX_N][MAX_N], ll b[MAX_N][MAX_N]) {
    ll temp[MAX_N][MAX_N] = {0, };

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            for (int k = 0; k < n; ++k) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = temp[i][j] % 1000;
    
    return;
}

void func() {
    ll res[MAX_N][MAX_N] = {0, };
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;

    while(b) {
        if (b % 2)
            mul(res, arr);
        mul(arr, arr);
        b /= 2;
    }
    for (int i = 0; i < n; ++i,cout<<endl)
        for (int j = 0; j < n; ++j)
            cout << res[i][j] % 1000 << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> b;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    func();

    return 0;
}
