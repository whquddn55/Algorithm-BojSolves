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

struct Data {
    bool t, b, l, r;
};

int n;
bool arr[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        
        vector<int> v;
        v.emplace_back(d);
        for (int j = 0; j < g; ++j) {
            int sz = v.size();
            for (int k = sz - 1; k >= 0; --k) {
                v.emplace_back((v[k] + 1) % 4);
            }
        }
        for (auto e : v) {
            arr[y][x] = true;
            if (e == 0) {
                x++;
            }
            else if (e == 1) {
                y--;
            }
            else if (e == 2) {
                x--;
            }
            else {
                y++;
            }
        }
        arr[y][x] = true;
    }
    int ans = 0;
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j) {
            ans += arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1];
        }
    cout << ans << endl;



    return 0;
}
