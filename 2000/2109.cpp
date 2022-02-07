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
#define MAX_N 10005
#define MOD 1'000'000'007

int n;
pii arr[MAX_N];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];
    
    sort(arr, arr + n, [](pii& a, pii& b) -> bool {return a.second > b.second;});

    int ans = 0;
    int index = 0;
    for(int i = 10000; i >= 1; --i) {
        while (index < n && arr[index].second == i) {
            pq.emplace(arr[index].first);
            ++index;
        }
        if (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;

    return 0;
}
