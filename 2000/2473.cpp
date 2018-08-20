#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 5000

int n;
int arr[MAX_N];

ll minValue = LLONG_MAX;
vector<int> ans(3);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int l = i + 1;
		int r = n - 1;
		while (l < r) {
			ll value = 1ll * arr[i] + arr[l] + arr[r];
			if (minValue > abs(value)) {
				minValue = abs(value);
				ans = { i, l, r };
			}
			if (value == 0) {
				for (auto e : ans)
					cout << arr[e] << ' ';
				exit(0);
			}
			else if (value < 0)
				l++;
			else
				r--;
		}
	}

	for (auto e : ans)
		cout << arr[e] << ' ';
	
	
	return 0;
}