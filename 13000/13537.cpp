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
vector<int> tree[4 * MAX_N];

void init(int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (nodeLeft == nodeRight) {
        tree[nodeIndex] = {arr[nodeLeft]};
        return;
    }
    int mid = (nodeLeft + nodeRight) / 2;
    init(nodeLeft, mid, nodeIndex * 2);
    init(mid + 1, nodeRight, nodeIndex * 2 + 1);
    auto it1 = tree[nodeIndex * 2].begin(), it2 = tree[nodeIndex * 2 + 1].begin();
    tree[nodeIndex].reserve(nodeRight - nodeLeft + 1);
    while (it1 != tree[nodeIndex * 2].end() && it2 != tree[nodeIndex * 2 + 1].end()) {
        if (*it1 >= *it2) {
            tree[nodeIndex].push_back(*it2);
            ++it2;
        }
        else {
            tree[nodeIndex].push_back(*it1);
            ++it1;
        }
    }
    while (it1 != tree[nodeIndex * 2].end()) {
        tree[nodeIndex].push_back(*it1);
        ++it1;
    }
    while(it2 != tree[nodeIndex * 2 + 1].end()) {
        tree[nodeIndex].push_back(*it2);
        ++it2;
    }
}

int query(int l, int r, int k, int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (r < nodeLeft || nodeRight < l)
        return 0;
    if (l <= nodeLeft && nodeRight <= r)
        return tree[nodeIndex].size() - (upper_bound(tree[nodeIndex].begin(), tree[nodeIndex].end(), k) - tree[nodeIndex].begin());
    int mid = (nodeLeft + nodeRight) / 2;
    return query(l, r, k, nodeLeft, mid, nodeIndex * 2) + query(l, r, k, mid + 1, nodeRight, nodeIndex * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    init();
    int q;
    cin >> q;
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i - 1, j - 1, k) << endl;
    }

	return 0;
}
