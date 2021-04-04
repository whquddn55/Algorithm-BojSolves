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

#define INF (INT_MAX / 2)

#define MAX_N 20

int n;
pii arr[MAX_N];

ll get(int l, int w, int h) {
    if (l == 0 || w == 0 || h == 0) {
        return 0;
    }

    ll ret = (ll)INF * INF;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i].second) {
            if (arr[i].first > l || arr[i].first > w || arr[i].first > h)
                continue;
            
            --arr[i].second;
            ret = min({ret,
                get(arr[i].first, arr[i].first, h - arr[i].first) +
                get(arr[i].first, w - arr[i].first, arr[i].first) +
                get(arr[i].first, w - arr[i].first, h - arr[i].first) +
                get(l - arr[i].first, arr[i].first, arr[i].first) +
                get(l - arr[i].first, arr[i].first, h - arr[i].first) +
                get(l - arr[i].first, w - arr[i].first, arr[i].first) +
                get(l - arr[i].first, w - arr[i].first, h - arr[i].first) + 1
            });
            break;
        }
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    int l, w, h;
    cin >> l >> w>> h;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin>> arr[i];
        arr[i].first = (1 << arr[i].first);
    }

    sort(arr, arr + n);

    ll result = get(l, w, h);
    cout << (result == (ll)INF * INF ? -1 : result) << endl;
    
	return 0;
}
