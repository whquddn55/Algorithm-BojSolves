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
#define MAX_N 100005
#define MOD 1000000007

int n, k, d;
pair<int, vector<int>> arr[MAX_N];
int cnt[31];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k >> d;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m >> arr[i].first;
        while(m--) {
            int t;
            cin >> t;
            arr[i].second.emplace_back(t);
        }
    }
    sort(arr, arr + n);

    int f = 0, t = 0;
    int ans = 0;
    while(t < n) {
        while(t < n && arr[t].first - arr[f].first <= d) {
            for (auto algo : arr[t].second)
                ++cnt[algo];

            int cntOfAlgo = 0;
            int everyKnow = 0;
            for (int i = 0; i <= 30; ++i) {
                if (cnt[i])
                    ++cntOfAlgo;
                if (cnt[i] == (t - f + 1))
                    ++everyKnow;
            }
            ans = max(ans, (cntOfAlgo - everyKnow) * (t - f + 1));
            ++t;
        }
        while(arr[t].first - arr[f].first > d) {
            for (auto algo : arr[f].second)
                --cnt[algo];
            ++f;
        }
        
    }
    cout << ans << endl;

    return 0;
}