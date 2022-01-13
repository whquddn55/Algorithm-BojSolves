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
#define MAX_N 100'005
#define MOD 1'000'000'007

int n, m;
set<pii> arr1[105];
set<pii> arr2;
int level[MAX_N];
int grade[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, l, g;
        cin >> p >> l >> g;
        arr1[g].emplace(l, p);
        arr2.emplace(l, p);
        level[p] = l;
        grade[p] = g;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (s == "recommend") {
            int g, x;
            cin >> g >> x;
            if (x == 1) {
                cout << arr1[g].rbegin()->second << endl;
            }
            else {
                cout << arr1[g].begin()->second << endl;
            }
        }
        else if (s == "recommend2") {
            int x;
            cin >> x;
            if (x == 1) {
                cout << arr2.rbegin()->second << endl;
            }
            else {
                cout << arr2.begin()->second << endl;
            }
        }
        else if (s == "recommend3") {
            int x, l;
            cin >> x >> l;
            if (x == 1) {
                auto it = arr2.lower_bound(pii(l, 0));
                if (it == arr2.end())
                    cout << -1 << endl;
                else 
                    cout << it->second << endl;
            }
            else {
                auto it = arr2.lower_bound(pii(l, 0));
                if (it == arr2.begin())
                    cout << -1 << endl;
                else 
                    cout << (--it)->second << endl;
            }
        }
        else if (s == "add") {
            int p, l, g;
            cin >> p >> l >> g;
            arr1[g].emplace(l, p);
            arr2.emplace(l, p);
            level[p] = l;
            grade[p] = g;
        }
        else {
            int p;
            cin >> p;
            arr1[grade[p]].erase(pii(level[p], p));
            arr2.erase(pii(level[p], p));
        }
    }

    return 0;
}
