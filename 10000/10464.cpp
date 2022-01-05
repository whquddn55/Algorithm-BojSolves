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
pii query[MAX_N];
vector<int> in;
pii ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> query[i];
        query[i].first--;
        in.emplace_back(query[i].first);
        in.emplace_back(query[i].second);
    }
    sort(all(in));
    in.erase(unique(all(in)), in.end());

    int psum = 0;
    int pointer = 0;
    for (int i = in.front(); i <= in.back(); ++i) {
        psum ^= i;
        if ((pointer < in.size()) && (in[pointer] == i)) {
            for (int j = 0; j < n; ++j) {
                if (query[j].first == i)
                    ans[j].first = psum;
                if (query[j].second == i) {
                    ans[j].second = psum;
                }
            }
            ++pointer;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << (ans[i].second ^ ans[i].first) << endl;

    return 0;
}
