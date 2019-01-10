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

#define MAX_N 1005

int n, c;
map<int, int> m;
pair<int, pii> arr[MAX_N];
int lastIndex = 1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (m.count(t)) 
			arr[m[t]].first++;
		else {
			arr[lastIndex] = { 1, pii(-i, t) };
			m[t] = lastIndex;
			lastIndex++;
		}
	}
	sort(arr + 1, arr + lastIndex, greater<pair<int, pii>>());
	for (int i = 1; i < lastIndex; ++i)
		for (int j = 0; j < arr[i].first; ++j)
			cout << arr[i].second.second << ' ';
	cout << endl;
	
	return 0;
}