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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 7
#define MOD 1000003

int n;
ll arr[MAX_N][MAX_N];

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n + 1; ++j)
			cin >> arr[i][j];

	for (int j = 0; j < n; ++j) {
		ll lcm = 1;
		if (arr[j][j] == 0) {
			for (int i = j; i < n; ++i)
				if (arr[i][j] != 0) {
					for (int k = 0; k < n + 1; ++k)
						swap(arr[j][k], arr[i][k]);
					break;
				}
		}
		for (int i = j; i < n; ++i) {
			if (arr[i][j] == 0)
				continue;
			ll g = gcd(lcm, arr[i][j]);
			lcm *= arr[i][j] / g;
		}

		for (int i = j; i < n; ++i) {
			if (arr[i][j] == 0)
				continue;
			ll temp = lcm / arr[i][j];
			
			for (int k = j; k < n + 1; ++k)
				arr[i][k] *= temp;
		}

		for (int i = j + 1; i < n; ++i) {
			if (arr[i][j] == 0)
				continue;
			for (int k = j; k < n + 1; ++k)
				arr[i][k] -= arr[j][k];

			ll g = arr[i][i];
			for (int k = j + 1; k < n; ++k) 
				g = gcd(g, arr[i][k]);
			for (int k = j + 1; k < n + 1; ++k) 
				arr[i][k] /= g;
		}
	}
	stack<ll> ans;
	for (int i = n - 1; i >= 0; --i) {
		ll now = arr[i][n] / arr[i][i];
		
		ans.push(now);
		for (int j = i - 1; j >= 0; --j)  {
			arr[j][n] -= arr[j][i] * now;
			arr[j][i] = 0;
		}
	}
	
	while(ans.size()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << endl;
	return 0;
}
