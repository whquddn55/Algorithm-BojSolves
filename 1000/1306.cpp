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
#define MAX_N 2000005
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N];
multiset<int> ms;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];

    assert(n >= 2 * m - 1);
    
    for (int i = 0; i < 2 * m - 1; ++i)
        ms.insert(arr[i]);

    for (int i = m - 1; i <= n - m; ++i) {
        if (m <= i) {
            ms.erase(ms.find(arr[i - m]));
            ms.insert(arr[i + m - 1]);
        }
        cout << *ms.rbegin() << endl;
    }

    return 0;
}
