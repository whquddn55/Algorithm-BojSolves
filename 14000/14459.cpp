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
#define MAX_N 100005
#define MOD 1000000

int n;
int arr[100005];
vector<int> adj[MAX_N];
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for (int j = max(1, t - 4); j <= min(n, t + 4); ++j)
            adj[j].emplace_back(i);
    }

    for (int i = 1; i <= n; ++i)
        sort(all(adj[i]), greater<int>());

    for (int i = 0; i < n; ++i) {
        for (int e : adj[arr[i]]) {
            auto idx = lower_bound(all(lis), e);
            if (idx == lis.end())
                lis.emplace_back(e);
            else
                *idx = e;
        }
    }
    cout << lis.size() << endl;
    
    return 0;
}
