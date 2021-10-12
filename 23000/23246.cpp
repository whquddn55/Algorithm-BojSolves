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

#define MAX_N 105

int n;
pair<pii, int> arr[MAX_N];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> arr[i].second >> a >> b >> c;
		arr[i].first.first = a * b * c;
		arr[i].first.second = a + b + c;
	}
	sort(arr, arr + n);
	for (int i = 0; i < 3; ++i)
		cout << arr[i].second << endl;
}