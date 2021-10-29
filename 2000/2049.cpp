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
#define MAX_N 100005

int n;
pii arr[MAX_N];
vector<pii> hull;

int ccw(pll a, pll b, pll c){ // 1: 반시계, -1 : 시계
    ll value = (a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second));
    return value ? (value > 0 ? 1 : -1) : 0;
}

void getConvexhull() {
    sort(arr, arr + n);
    sort(arr + 1, arr + n, [](pii& a, pii& b)-> bool {
        int v = ccw(arr[0], a, b);
        if (v)
            return v == 1;
        return a < b;
    });


    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], arr[i]) <= 0) 
            hull.pop_back();
        hull.emplace_back(arr[i]);
    }
    return;
}

ll dist(pll a, pll b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void ratingCalipers() {
    int p = 1;
    ll ans = 0;
    pii ans1, ans2;
    int sz = hull.size();
    for (int i = 0; i < sz; ++i) {
        int b = (i + 1) % sz;
        int d = (p + 1) % sz;
        while((p + 1) != i && ccw(hull[i], hull[b], pii(hull[d].first - (hull[p].first - hull[b].first), hull[d].second - (hull[p].second - hull[b].second))) > 0) {
            if (ans < dist(hull[i], hull[p % sz])) {
                ans1 = hull[i];
                ans2 = hull[p];
                ans = dist(hull[i], hull[p % sz]);
            }
            ++p;
            p %= sz;
            d = (p + 1) % sz;
        }
        if (ans < dist(hull[i], hull[p])) {
            ans1 = hull[i];
            ans2 = hull[p];
            ans = dist(hull[i], hull[p]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    hull.clear();

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    getConvexhull();
    ratingCalipers();
    
    return 0;
}
