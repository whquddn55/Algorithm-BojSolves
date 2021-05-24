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
#define MAX_N 5000002
#define MOD 1000000007

int n, l;
list<pii> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        while(q.size() && q.front().second + l <= i)
            q.pop_front();
        while(q.size() && q.back().first >= t)
            q.pop_back();
        q.emplace_back(t, i);
        cout << q.front().first << ' ';
    }
    
    return 0;
}