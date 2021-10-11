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
#define MOD 1000000007

ll w, h, l;
ll arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> w >> h >> l;
	if (w < h)
		swap(w, h);

	ll res = 0;
	ll y = 0;
	for (ll x = -l; x < 0; ++x) {
		int sum = 0;
		while(x * x + (y+1) * (y+1) <= l * l)
			++y;
		res += y * 3 + 1;
	}
	res += l;

	y = l;
	for (ll x = 0; x < l - h; ++x) {
		while(x * x + y * y > (l - h) * (l - h))
			--y;
		arr[x] = y + h;
	}

	y = l - w;
	for (ll x = 0; x < l - w; ++x) {
		while(x * x + y * y > (l - w) * (l - w))
			--y;
		arr[x + w] = max(arr[x + w], y);
	}

	for (ll x = 0; x <= l; ++x) {
		if (x <= w && arr[x] <= h)
			continue;
		if (x <= w)
			res += arr[x] - h;
		else
			res += arr[x] + 1;
	}
	
	cout << res << endl;
	
	return 0;
}