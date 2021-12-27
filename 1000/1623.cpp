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
#define MAX_N 200005
#define MOD 1'000'000'007

int n;
int arr[MAX_N];
int dp[MAX_N][2];
vector<int> adj[MAX_N];
bool picked[MAX_N][2];
pair<int, vector<int>> ans1, ans2;

vector<int> track;

int getDp(int i1, int i2) {
    int& ret = dp[i1][i2];
    if (ret != -1)
        return ret;

    ret = 0;
    int sum = 0;
    if (i2) {
        for (int nxt : adj[i1]) {
            sum += getDp(nxt, 0);
        }
        ret = sum + arr[i1];
        picked[i1][i2] = true;
    }
    
    sum = 0;
    for (int nxt : adj[i1]) {
        sum += getDp(nxt, 1);
    }
    if (ret < sum) {
        ret = sum;
        picked[i1][i2] = false;
    }
    return ret;
}

void backtrack(int here, bool t) {
    if (picked[here][t] == true) {
        track.emplace_back(here);
        for (int nxt : adj[here])
            backtrack(nxt, false);
    }
    else {
        for (int nxt : adj[here])
            backtrack(nxt, true);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 1; i < n; ++i) {
        int t;
        cin >> t;
        --t;
        
        adj[t].emplace_back(i);
    }

    memset(dp, -1, sizeof(dp));
    int sum = arr[0];
    for (int nxt : adj[0])
        sum += getDp(nxt, 0);
    ans1.first = sum;

    // backtrack
    picked[0][1] = true;
    backtrack(0, 1);
    sort(all(track));
    ans1.second = track;

    memset(dp, -1, sizeof(dp));
    memset(picked, 0, sizeof(picked));
    ans2.first = getDp(0, 0);

    // backtrack
    track.clear();
    backtrack(0, 0);
    sort(all(track));
    ans2.second = track;

    cout << pii(ans1.first, ans2.first) << endl;
    for (auto e : ans1.second)
        cout << e + 1 << ' ';
    cout << -1 << endl;
    for (auto e : ans2.second)
        cout << e + 1 << ' ';
    cout << -1 << endl;

    return 0;
}
