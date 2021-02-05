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

#define MAX_N 300005

int n, q;
int arr[MAX_N];
int sum[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
		sum[i] = (i ? sum[i - 1] : 0) + arr[i];


	while (q--) {
		int f, t;
		cin >> f >> t;
		f--;
		t--;
		cout << sum[t] - (f ? sum[f - 1] : 0) << endl;
	}

	return 0;
}