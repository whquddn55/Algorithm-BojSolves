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

int a, b;


int main() {
    ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> a >> b;

    int result = 0;
    while (a != b && a < b) {
        ++result;
        if (b % 10 == 1)
            b /= 10;
        else if (b % 2 == 0)
            b /= 2;
        else
            break;
    }

    if (a != b)
        cout << -1 << endl;
    else
        cout << result + 1 << endl;

    return 0;
}
