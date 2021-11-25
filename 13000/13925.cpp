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

#define all(x) (x.begin(), x.end())
#define INF (INT_MAX / 2)
#define MAX_N 100'005
#define MOD 1'000'000'007

int n;
ll tree[MAX_N * 4];
ll lazy1[MAX_N * 4]; // sum
ll lazy2[MAX_N * 4]; // mul

ll sum(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

void updateLazy(int nodeLeft, int nodeRight, int id) {
    if (lazy1[id] != 0 || lazy2[id] != 1) {
        tree[id] = sum(mul(tree[id], lazy2[id]), mul(nodeRight - nodeLeft + 1, lazy1[id]));
        if (nodeLeft != nodeRight) {
            lazy1[id * 2] = sum(lazy1[id],  mul(lazy1[id * 2], lazy2[id]));
            lazy1[id * 2 + 1] = sum(lazy1[id],  mul(lazy1[id * 2 + 1], lazy2[id]));
            lazy2[id * 2] = mul(lazy2[id * 2], lazy2[id]);
            lazy2[id * 2 + 1] = mul(lazy2[id * 2 + 1], lazy2[id]);
        }
        lazy1[id] = 0;
        lazy2[id] = 1;
    }
}

void update(int left, int right, ll val1, ll val2, int nodeLeft = 1, int nodeRight = n, int id = 1) {
    int mid = (nodeLeft + nodeRight) / 2;
    updateLazy(nodeLeft, nodeRight, id);
    if (right < nodeLeft || nodeRight < left)
        return;
    if (left <= nodeLeft && nodeRight <= right) {
        lazy1[id] = sum(mul(lazy1[id], val2), val1);
        lazy2[id] = mul(lazy2[id], val2);
        updateLazy(nodeLeft, nodeRight, id);
        return;
    }
    update(left, right, val1, val2, nodeLeft, mid, id * 2);
    update(left, right, val1, val2, mid + 1, nodeRight, id * 2 + 1);
    tree[id] = sum(tree[id * 2], tree[id * 2 + 1]);
}

ll query(int left, int right, int nodeLeft = 1, int nodeRight = n, int id = 1) {
    int mid = (nodeLeft + nodeRight) / 2;
    updateLazy(nodeLeft, nodeRight, id);
    if (right < nodeLeft || nodeRight < left)
        return 0;
    if (left <= nodeLeft && nodeRight <= right) 
        return tree[id];
    
    return sum(query(left, right, nodeLeft, mid, id * 2), query(left, right, mid + 1, nodeRight, id * 2 + 1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        update(i + 1, i + 1, t, 1);
    }

    int m;
    cin >> m;
    while (m--) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 1) {
            int v;
            cin >> v;
            update(x, y, v, 1);
        }
        else if (c == 2) {
            int v;
            cin >> v;
            update(x, y, 0, v);
        }
        else if (c == 3) {
            int v;
            cin >> v;
            update(x, y, v, 0);
        }
        else {
            cout << query(x, y) << endl;
        }
    }

    return 0;
}
