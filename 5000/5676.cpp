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
#define MAX_N 100005
#define MOD 1'000'000'007

int n, k;
int arr[MAX_N];
int tree[MAX_N * 4];

void init(int id = 1, int nl = 0, int nr = MAX_N - 1) {
    int mid = (nl + nr) / 2;
    if (nl == nr) {
        tree[id] = arr[nl] == 0 ? 0 : (arr[nl] > 0 ? 1 : -1);
        return;
    }
    init(id * 2, nl, mid);
    init(id * 2 + 1, mid + 1, nr);
    tree[id] = tree[id * 2] * tree[id * 2 + 1];
}

void update(int index, int value, int id = 1, int nl = 0, int nr = MAX_N - 1) {
    int mid = (nl + nr) / 2;
    if (index < nl || nr < index)
        return;
    if (nl == nr) {
        tree[id] = value;
        return;
    }
    update(index, value, id * 2, nl, mid);
    update(index, value, id * 2 + 1, mid + 1, nr);
    tree[id] = tree[id * 2] * tree[id * 2 + 1];
}

int query(int l, int r, int id = 1, int nl = 0, int nr = MAX_N - 1) {
    int mid = (nl + nr) / 2;
    if (r < nl || nr < l)
        return 1;
    if (l <= nl && nr <= r)
        return tree[id];
    return query(l, r, id * 2, nl, mid) * query(l, r, id * 2 + 1, mid + 1, nr);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> k) {
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        init();

        while(k--) {
            char a;
            int b, c;
            cin >> a >> b >> c;
            if (a == 'C') {
                update(b - 1, c == 0 ? 0 : (c > 0 ? 1 : -1));
            }
            else {
                int res = query(b - 1, c - 1);
                cout << (res == 0 ? '0' : (res > 0 ? '+' : '-'));
            }
        }
        cout << endl;
    }

    return 0;
}
