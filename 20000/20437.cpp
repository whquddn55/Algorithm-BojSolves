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
#define MAX_N 1005
#define MOD 1'000'000'007

int n;
string s;
int k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int tc = 0; tc < n; ++tc) {
        cin >> s >> k;
        pii ans = {INF, -1};

        vector<int> arr[30];
        for (int i = 0; i < s.size(); ++i) {
            int here = s[i] - 'a';
            arr[here].emplace_back(i);
            if (arr[here].size() >= k) {
                ans.first = min(ans.first, i - arr[here][arr[here].size() - k] + 1);
                ans.second = max(ans.second, i - arr[here][arr[here].size() - k] + 1);
            }
        }
        if (ans.first == INF || ans.second == -1)
            cout << -1 << endl;
        else
            cout << ans << endl;
    } 

    return 0;
}
