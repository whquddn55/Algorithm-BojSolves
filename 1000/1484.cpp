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

#define MAX_N 20

int g;
vector<int> result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> g;

    for (int i = 1; i * i < g; ++i) {
        if (g % i == 0) {
            int t = g / i;
            if ((t + i) % 2)
                continue;
            result.emplace_back((t + i) / 2);
        }
    }
    sort(result.begin(), result.end());
    if (result.empty())
        cout << -1 << endl;
    else {
        for (auto e : result)
            cout << e << endl;
    }
    
	return 0;
}
