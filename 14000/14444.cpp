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
#define MOD 10007

string s;
int man[MAX_N * 2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    char c;
    s.push_back('@');
    while(cin >> c) {
        s.push_back(c);
        s.push_back('@');
    }

    int r = 0;
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i <= r) {
            man[i] = min(r - i, man[p * 2 - i]);
        }
        while(i - man[i] >= 0 && i + man[i] < s.size() && s[i - man[i]] == s[i + man[i]])
            ++man[i];
        --man[i];

        if (r < i + man[i]) {
            r = i + man[i];
            p = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < s.size();++i)
        ans = max(ans, man[i]);
    cout << ans << endl;
    
    return 0;
}