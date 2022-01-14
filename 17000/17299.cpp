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
#define MAX_N 1'000'005
#define MOD 1'000'000'007

int n;
int arr[MAX_N];
int cnt[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    stack<pii> st;
    stack<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (st.empty()) {
            ans.emplace(-1);
            st.emplace(cnt[arr[i]], arr[i]);
        }
        else {
            if (st.top().first > cnt[arr[i]])
                ans.emplace(st.top().second);
            else {
                while(st.size() && st.top().first <= cnt[arr[i]])
                    st.pop();

                if (st.size())
                    ans.emplace(st.top().second);
                else
                    ans.emplace(-1);
            }
            st.emplace(cnt[arr[i]], arr[i]);
        }
    }

    while(ans.size()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
