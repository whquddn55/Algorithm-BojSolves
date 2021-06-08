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
#define MAX_N 10005
#define MOD 9901

int n;
int arr[MAX_N];
vector<int> adj[MAX_N];

int dp[MAX_N][2];

int getDp(int i1, bool i2, int parent) {
    int& ret = dp[i1][i2];
    if (ret != -1)
        return ret;

    if (i2) {
        int sum = arr[i1 - 1];
        for(auto c : adj[i1])
            if (c != parent)
                sum += getDp(c, false, i1);
        int maxSum = sum;
        sum = 0;
        for(auto c : adj[i1])
            if (c != parent)
                sum += getDp(c, true, i1);
        maxSum = max(maxSum, sum);
        ret = maxSum;
    }
    else {
        ret = 0;
        for(auto c : adj[i1])
            if (c != parent)
                ret += getDp(c, true, i1);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    memset(dp, -1, sizeof(dp));
    cout << getDp(1, true, 1) << endl;

    return 0;
}