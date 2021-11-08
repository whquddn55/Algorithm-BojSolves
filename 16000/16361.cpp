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
#define MAX_N 300005
#define MOD 1000000

int n;
pii arr[MAX_N];

bool decide(int error) {
    ll cnt = 0;
    ll minV = 0;
    ll maxV = 0;
    ll prv = 0;
    for (int i = 0; i < n; ++i) {
        minV = min(minV, (ll)arr[i].second);
        maxV = max(maxV, (ll)arr[i].second);

        if (cnt == 0) {
            if (maxV > error) {
                ++cnt;
                minV = arr[i].second;
                maxV = arr[i].second;
            }
        }
        else {
            if ((maxV - minV) / 2 > error) {
                ++cnt;
                prv = (minV + maxV) / 2;
                minV = arr[i].second;
                maxV = arr[i].second;
            }
        }
        if (cnt == 3)
            break;
    }
    
    if (cnt <= 2 && prv <= (minV + maxV) / 2) 
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i].second *= 2;
    }
    sort(arr, arr + n);

    ll l = arr[0].first == 0 ? arr[0].second : 0;
    ll r = 2e9;
    ll ans;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (decide(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans / 2 << '.' << (ans & 1 ? 5 : 0) << endl;
    
    return 0;
}
