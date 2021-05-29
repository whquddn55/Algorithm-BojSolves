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
#define MAX_N 500005
#define MOD 1000000007

int n;
int arr[MAX_N];
int compress[MAX_N];

int tree[2 * MAX_N];

void update(int index, int value) {
    index += n;
    tree[index] = value;
    index >>= 1;
    for (; index > 0; (index >>= 1)) 
        tree[index] = tree[index << 1] + tree[(index << 1) + 1];
}

int query(int l, int r) {
    l += n;
    r += n + 1;
    int ret = 0;
    while(l < r) {
        if (l & 1) {
            ret += tree[l];
            ++l;
        }
        if (r & 1) {
            --r;
            ret += tree[r];
        }
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        compress[i] = arr[i];
    }
    sort(compress, compress + n);
    for (int i = 0; i < n; ++i) {
        int value = lower_bound(compress, compress + n, arr[i]) - compress;
        cout << (i + 1) - query(0, value) << endl;
        update(value, 1);
    }

    return 0;
}