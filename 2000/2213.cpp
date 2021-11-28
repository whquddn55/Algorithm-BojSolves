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
int arr[MAX_N];
vector<int> adj[MAX_N];
int dp[MAX_N][2];
bool picked[MAX_N][2];
vector<int> ans;

int getDp(int i1, int i2, int prv) {
    int& ret = dp[i1][i2];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int nxt : adj[i1]) {
        if (nxt == prv)
            continue;
        ret += getDp(nxt, 1, i1);
    }

    if (i2 == 1) {
        int temp = arr[i1];
        // pick함
        for (int nxt : adj[i1]) {
            if (nxt == prv)
                continue;
            temp += getDp(nxt, 0, i1);
        }
        if (ret < temp) {
            ret = temp;
            picked[i1][i2] = true;
        }
    }
    return ret;
}

void getAns(int i1, int i2, int prv) {
    if (picked[i1][i2]) {
        ans.emplace_back(i1);
        for (int nxt : adj[i1]) {
            if (nxt == prv)
                continue;
            getAns(nxt, 0, i1);
        }
    }
    else {
        for (int nxt : adj[i1]) {
            if (nxt == prv)
                continue;
            getAns(nxt, 1, i1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n - 1; ++i) {
        int f, t;
        cin >> f >> t;
        adj[f].emplace_back(t);
        adj[t].emplace_back(f);
    }

    memset(dp, -1, sizeof(dp));
    cout << getDp(1, 1, 0) << endl;
    getAns(1, 1, 0);
    sort(all(ans));
    for (int a : ans)
        cout << a << ' ';
    cout << endl;
    
    return 0;
}
