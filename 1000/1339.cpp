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
#define MAX_N 1005

int n;
int value[50];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int offset = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            value[s[i] - 'A'] += offset;
            offset *= 10;
        }
    }
    sort(value, value + 50, greater<int>());

    int ans = 0;
    for (int i = 9; i >= 0; --i) {
        ans += value[9 - i] * i;
    }
    cout << ans << endl;

    return 0;
}
