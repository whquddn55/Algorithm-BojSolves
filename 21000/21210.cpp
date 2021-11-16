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
#define MAX_N 1005
#define MOD 1000000

int x, y;
int n;
pair<double, double> arr[MAX_N];
int parent[MAX_N];

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[u] = v;
    }
}

bool decide(double r) {
    int check[MAX_N] = {0, };
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            double dist = sqrt((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) +
            (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));

            if (dist < r * 2)
                merge(i, j);
        }

    for (int i = 0; i < n; ++i) {
        int node = find(i);
        if (abs(arr[i].second - y) < r)
            check[node] |= 0b0001;
        if (arr[i].second < r)
            check[node] |= 0b0010;
        if (abs(arr[i].first - x) < r)
            check[node] |= 0b0100;
        if (arr[i].first < r)
            check[node] |= 0b1000;
    }

    for (int i = 0; i < n; ++i) {
        int node = find(i);
        if (((check[node] & 0b11) == 0b11) || ((check[node] & 0b1100) == 0b1100) || ((check[node] & 0b0101) == 0b0101) || ((check[node] & 0b1010) == 0b1010))
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> x >> y;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    double l = 0;
    double r = 1e15;
    double ans;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if (decide(mid)) {
            ans = mid;
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << ans << endl;
    
    return 0;
}
