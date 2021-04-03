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

#define MAX_N 40

int n, s;
int arr[MAX_N];
map<int, int> a, b;

void pick(int toPick, int to, map<int, int>& v, int sum) {
    if (toPick == to) {
        v[sum] += 1;
        return;
    }

    pick(toPick + 1, to, v, sum + arr[toPick]);
    pick(toPick + 1, to, v, sum);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    pick(0, n / 2 , a, 0);
    pick(n / 2, n, b, 0);

    auto l = a.begin();
    auto r = b.rbegin();
    ll result = 0;
    while(l != a.end() && r != b.rend()) {
        if (l->first + r->first > s) 
            r++;
        else if (l->first + r->first < s)
            l++;
        else {
            result += (ll)l->second * r->second;
            l++;
            r++;
        }
    }
    
    if (s == 0)
        --result;
    cout << result << endl;

	return 0;
}
