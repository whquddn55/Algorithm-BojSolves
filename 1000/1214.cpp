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
#define MAX_N 4005
#define MOD 1000000007

int a, b, c;

int gcd(int a, int b) {
    while(b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> c >> a >> b;
    ll lcm = ((ll)a / gcd(a, b) * b);
    if ( a < b)
        swap(a, b);
    int minValue = INF;
    for (int i = 0; i <= min(b - 1, c / a + 1); ++i) {
        int remain = (c - a * i);
        if (remain < 0) {
            minValue = min(minValue, -remain);
            continue;
        }
        remain -= (remain / b * b);
        if (remain > 0)
            remain -= b;
        minValue = min(minValue, -remain);
    }
    cout << c + minValue << endl;
    

    return 0;
}