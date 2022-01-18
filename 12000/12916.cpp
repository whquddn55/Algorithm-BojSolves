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

int n, k;


struct Matrix {
    int arr[MAX_N][MAX_N];
} origin;

Matrix mul(Matrix& a, Matrix& b) {
    Matrix res;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            res.arr[i][j] = 0;
            for (int k = 0; k < n; ++k)
                res.arr[i][j] = (res.arr[i][j] + ((ll)a.arr[i][k] * (ll)b.arr[k][j]) % MOD) % MOD;
        }
    return res;
}

Matrix pow(int v) {
    Matrix res;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            res.arr[i][j] = (i == j);
        
    while (v) {
        if (v % 2) {
            res = mul(res, origin);
        }
        v /= 2;
        origin = mul(origin, origin);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n ;++i)
        for (int j = 0; j < n ;++j)
            cin >> origin.arr[i][j];

    Matrix res = pow(k);
    int ans = 0;
    for (int i = 0; i < n ;++i)
        for (int j = 0; j < n ;++j) {
            ans = (ans + res.arr[i][j]) % MOD;
        }
    cout << ans << endl;

    return 0;
}
