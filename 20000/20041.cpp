#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_N 500005

int n;
pii arr[MAX_N];
pii c;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;
	cin >> c.first >> c.second;

	bool r1 = true, r2 = true, r3 = true, r4 = true; 
	for (int i = 0; i < n; ++i) {
		if (c.first - arr[i].first <= 0) {
			if (abs(c.first - arr[i].first) >= abs(c.second - arr[i].second))
				r1 = false;
		}
		else if (c.first - arr[i].first > 0) {
			if (abs(c.first - arr[i].first) >= abs(c.second - arr[i].second))
				r2 = false;
		} 
		if (c.second - arr[i].second <= 0) {
			if (abs(c.second - arr[i].second) >= abs(c.first - arr[i].first))
				r3 = false;
		}
		if (c.second - arr[i].second > 0) {
			if (abs(c.second - arr[i].second) >= abs(c.first - arr[i].first))
				r4 = false;
		}
	}

	cout << ((r1 || r2 || r3 || r4) ? "YES" : "NO") << endl;

	return 0;
}