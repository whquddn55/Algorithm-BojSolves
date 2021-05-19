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

int n;
int arr[MAX_N];
ll tree[4 * MAX_N];
vector<pii> q1;
vector<pair<pii, pii>> q2;

ll init(int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (nodeLeft == nodeRight)
        return tree[nodeIndex] = arr[nodeLeft];
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[nodeIndex] = init(nodeLeft, mid, nodeIndex * 2) + init(mid + 1, nodeRight, nodeIndex * 2 + 1);
}

ll update(int index, int value, int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (index < nodeLeft || nodeRight < index)
        return tree[nodeIndex];
    if (nodeLeft == nodeRight) 
        return tree[nodeIndex] = value;
    
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[nodeIndex] = update(index, value, nodeLeft, mid, nodeIndex * 2) + update(index, value, mid + 1, nodeRight, nodeIndex * 2 + 1);
}

ll query(int l, int r, int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (r < nodeLeft || nodeRight < l)
        return 0;
    if (l <= nodeLeft && nodeRight <= r)
        return tree[nodeIndex];

    int mid = (nodeLeft + nodeRight) / 2;
    return query(l, r, nodeLeft, mid, nodeIndex * 2) + query(l, r, mid + 1, nodeRight, nodeIndex * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    init();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1)
            q1.emplace_back(b - 1, c);
        else {
            cin >> d;
            q2.emplace_back(pii(b - 1, q2.size()), pii(c - 1, d - 1));
        }
    }
    sort(q2.begin(), q2.end());
    ll result[MAX_N];
    int prv = -1;
    for (auto e : q2) {
        if ((e.first.first != -1) && (q1[e.first.first].first != -1)) {
            for (int i = prv + 1; i <= e.first.first; ++i) {
                update(q1[i].first, q1[i].second);
                q1[i].first = -1;
            }
            prv = e.first.first;
        }
        result[e.first.second] = query(e.second.first, e.second.second);
    }
    for (int i = 0; i < q2.size(); ++i)
        cout << result[i] << endl;

	return 0;
}
