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
#define MAX_N 55
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n;
vector<int> st;
ll ans = -1;
void get(int digit) {
    if (digit == -1) {
        --n;
        if (n == 0) {
            ans = 0;
            for (auto e : st)
                ans = ans * 10 + e;
        }
        return;
    }
    int prv = st.empty() ? 10 : st.back();
    for (int i = digit; i < prv; ++i) {
        st.push_back(i);
        get(digit - 1);
        st.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i <= 9; ++i) {
        get(i);
    }
    cout << ans << endl;
    
    return 0;
}