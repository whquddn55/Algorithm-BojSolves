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
#define MAX_N 50005
#define MOD 1'000'000'007

int n;
pll arr[MAX_N];
ll tree[MAX_N * 4];

ll update(int index, ll value, int nl = 0, int nr = MAX_N - 1, int id = 1) {
    int mid = (nl + nr) / 2;
    if (index < nl || nr < index)
        return tree[id];
    if (nl == nr)
        return tree[id] = value;
    return tree[id] = max(update(index, value, nl, mid, id * 2), update(index, value, mid + 1, nr, id * 2 + 1));
}

ll query(int l, int r, int nl = 0, int nr = MAX_N - 1, int id = 1) {
    int mid = (nl + nr) / 2;
    if (r < nl || nr < l)
        return 0;
    if (l <= nl && nr <= r)
        return tree[id];
    return max(query(l, r, nl, mid, id * 2), query(l , r, mid + 1, nr, id * 2 + 1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        update(i, arr[i].second);
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
            ll f, t;
            cin >> f >> t;
            int indexF = lower_bound(arr, arr + n, pll(f, 0)) - arr;
            int indexT = lower_bound(arr, arr + n, pll(t, 0)) - arr;
            pll valueF = arr[indexF];
            pll valueT = arr[indexT];

            bool condition1 = (indexT - indexF == t - f);
            bool condition2 = (valueF.second >= valueT.second);
            bool condition3 = (query(indexF + 1, indexT - 1) < valueT.second);

            if (valueF.first != f && valueT.first != t) {
                cout << "maybe" << endl;
            }
            else if (valueF.first == f && valueT.first != t) {
                if (query(indexF + 1, indexT - 1) >= valueF.second) {
                    cout << "false" << endl;
                }
                else {
                    cout << "maybe" << endl;
                }
            }
            else if (valueF.first != f && valueT.first == t) {
                if (query(indexF, indexT - 1) >= valueT.second) {
                    cout << "false" << endl;
                }
                else {
                    cout << "maybe" << endl;
                }
            }
            else {
                if (indexT - indexF == t - f) {
                    if ((valueF.second >= valueT.second) && (query(indexF + 1, indexT - 1) < valueT.second)) {
                        cout << "true" << endl;
                    }
                    else {
                        cout << "false" << endl;
                    }
                }
                else {
                    if ((valueF.second >= valueT.second) && (query(indexF + 1, indexT - 1) < valueT.second)) {
                        cout << "maybe" << endl;
                    }
                    else {
                        cout << "false" << endl;
                    }
                }
            }
        
    }

    return 0;
}
