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
#define MAX_N 100005
#define MOD 1'000'000'007

int a, b, n;
ll arr[MAX_N];
ll psum1[MAX_N], psum2[MAX_N];
ll sz1, sz2;

vector<pll> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> n;
    arr[0] = LLONG_MAX;
    for (int i = 1; i < n; ++i)
        cin >> arr[i];

    sz1 = n / 2;
    for (int i = 1; i <= sz1; ++i) {
        psum1[i] = psum1[i - 1] + arr[i * 2 - 1];
    }
    sz2 = (n - 1) / 2;
    for (int i = 1; i <= sz2; ++i) {
        psum2[i] = psum2[i - 1] + arr[i * 2];
    }

    /* case1 형이 받을 때 */
    for (int i = 1; i <= sz1 + (sz1 == sz2); ++i) {
        ll sum1 = psum2[sz2] - psum2[i - 1] + psum1[i - 1];
        ll sum2 = psum1[sz1] - psum1[i - 1] + psum2[i - 1];
        ll diff = sum1 - sum2;

        pll temp = make_pair(max(arr[i * 2 - 1], a - diff), min(arr[i * 2 - 2], b - diff));
        if (temp.first > temp.second)
            continue;
        temp.first = max(1LL, temp.first);
        ans.emplace_back(temp);
    }

    /* case2 동생이 받을 때 */
    for (int i = 1; i <= sz2 + !(sz1 == sz2); ++i) {
        ll sum1 = psum2[sz2] - psum2[i - 1] + psum1[i];
        ll sum2 = psum1[sz1] - psum1[i] + psum2[i - 1];
        ll diff = sum1 - sum2;

        pll temp = make_pair(max(arr[i * 2], diff - b), min(arr[i * 2 - 1], diff - a));
        if (temp.first > temp.second)
            continue;
        temp.first = max(1LL, temp.first);
        ans.emplace_back(temp);
    }
    sort(all(ans));
    pll here = ans[0];
    ll res = 0;
    for (pll e : ans) {
        if (here.second < e.first) {
            res += here.second - here.first + 1;
            here = e;
        }
        else {
            here.second = e.second;
        }
    }
    res += here.second - here.first + 1;
    cout << res << endl;

    return 0;
}
