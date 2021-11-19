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
#define MAX_N 13
#define MOD 1000000

int n;
pii arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, arr[i].second / arr[i].first);
    }

    cout << ans << endl;
    
    
    return 0;
}
