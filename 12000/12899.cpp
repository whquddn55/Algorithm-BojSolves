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
#define MAX_N 2000005
#define MOD 1000000

int n;
int tree[MAX_N * 4];

void update(int index, int value, int id = 1, int nl = 0, int nr = MAX_N - 1) {
    int mid = (nl + nr) / 2;
    if (index < nl || index > nr)
        return;
    if (nl == nr) {
        tree[id] += value;
        return;
    }
    update(index, value, id * 2, nl, mid);
    update(index, value, id * 2 + 1, mid + 1, nr);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int cnt, int id = 1, int nl = 0, int nr = MAX_N - 1) {
    int mid = (nl + nr) / 2;
    if (nl == nr) {
        return nl;
    }
    if (tree[id * 2] >= cnt)
        return query(cnt, id * 2, nl, mid);
    return query(cnt - tree[id * 2], id * 2 + 1, mid + 1, nr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    while(n--) {
        int q, x;
        cin >> q>> x;
        if (q == 1) {
            update(x, 1);
        }
        else {
            int ans = query(x);
            cout << ans << endl;
            update(ans, -1);
        }
    }
    
    return 0;
}
