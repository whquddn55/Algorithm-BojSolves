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
#define MAX_N 100005
#define MOD 1000000

int n;
int arr[3];
int idx[MAX_N];
int two[MAX_N];

int get(int here, int to) {
    if (here == 0)
        return 0;

    if (idx[here] == to)
        return get(here - 1, to);

    int temp = -1;
    for (int i = 0; i <= 2; ++i)
        if ((i != idx[here]) && (i != to))
            temp = i;
    assert(temp >= 0);

    return (get(here - 1, temp) + two[here - 1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> arr[i];
    for (int i = 0; i < 3; ++i) {
        while (arr[i]--) {
            int t;
            cin >> t;
            idx[t] = i;
        }
    }

    two[0] = 1;
    for (int i = 1; i <= n; ++i)
        two[i] = (two[i - 1] * 2) % MOD;

    cout << idx[n] + 1 << endl;
    cout << get(n, idx[n]) << endl;

    
    return 0;
}
