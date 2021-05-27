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
#define MAX_N 200005
#define MOD 1000000007

int n;
pll tree[4 * MAX_N];

pll update(int index, int nodeLeft = 0, int nodeRight = MAX_N, int nodeIndex = 1) {
    if (index < nodeLeft || nodeRight < index)
        return tree[nodeIndex];
    if (nodeLeft == nodeRight) {
        tree[nodeIndex].first++;
        tree[nodeIndex].second += index;
        return tree[nodeIndex];
    }
    int mid = (nodeLeft + nodeRight) / 2;
    pll lvalue = update(index, nodeLeft, mid, nodeIndex * 2);
    pll rvalue = update(index, mid + 1, nodeRight, nodeIndex * 2 + 1);
    return tree[nodeIndex] = pll(lvalue.first + rvalue.first, lvalue.second + rvalue.second);
}

pll query(int l, int r, int nodeLeft = 0, int nodeRight = MAX_N, int nodeIndex = 1) {
    if (r < nodeLeft || nodeRight < l)
        return {0, 0};
    if (l <= nodeLeft && nodeRight <= r) 
        return tree[nodeIndex];
    
    int mid = (nodeLeft + nodeRight) / 2;
    pll lvalue = query(l, r, nodeLeft, mid, nodeIndex * 2);
    pll rvalue = query(l, r, mid + 1, nodeRight, nodeIndex * 2 + 1);
    return pll(lvalue.first + rvalue.first, lvalue.second + rvalue.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    ll result = 1;
    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;
        if (i) {
            pll lquery = query(0, pos - 1);
            pll rquery = query(pos + 1, MAX_N);
            ll temp = pos * (lquery.first - rquery.first) - (lquery.second - rquery.second);
            result = (result * (temp % MOD)) % MOD;
        }
        update(pos);
    }

    cout << result << endl;
    
    return 0;
}