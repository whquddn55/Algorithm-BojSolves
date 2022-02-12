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
#define MAX_N 400005
#define MOD 1'000'000'007

int n;
vector<pii> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, r;
        cin >> x >> r;
        arr.emplace_back(x - r, i);
        arr.emplace_back(x + r, -i);
    }
    sort(all(arr));

    stack<int> st;
    bool ans = true;
    int prv = -INF;
    for (auto& p : arr) {
        if (p.second > 0) {
            st.push(p.second);
        }
        else {
            if (st.empty() || st.top() != -p.second) {
                ans = false;
            }
            st.pop();
        }

        if (p.first == prv) {
            ans = false;
        }
        prv = p.first;
    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
