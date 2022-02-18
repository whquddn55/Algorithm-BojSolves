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
#define MAX_N 100005
#define MOD 1'000'000'007

int n;
vector<pll> arr;

int ccw(pll a, pll b, pll c) { // 1: 반시계, -1 : 시계
    ll ret = (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);
    return ret ? ret / abs(ret) : ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pii t;
        cin >> t;
        char tt;
        cin >> tt;
        if (tt == 'Y')
            arr.emplace_back(t);
    }

    sort(all(arr));
    sort(arr.begin() + 1, arr.end(), [](pll& a, pll& b)-> bool {
        int v = ccw(arr[0], a, b);
        if (v)
            return v == 1;
        return a < b;
    });

    int index = arr.size() - 1;
    for (int i = arr.size() - 2; i >= 0; --i) {
        if (ccw(arr[0], arr[i + 1], arr[i]) == 0) {
            index = i;
        } else {
            break;
        }
    }

    assert(arr.size() >= 3);

    cout << arr.size() << endl;
    for (int i = 0; i < index; ++i)
        cout << arr[i] << endl;
    for (int i = arr.size( ) - 1; i >= index; --i)
        cout << arr[i] << endl;
    
    return 0;
}
