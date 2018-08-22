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

#define MAX_N 1025

int n, m;
int arr[MAX_N][MAX_N];
int sum[MAX_N][MAX_N]; // i번째 row의 j번째 column까지의 합

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = sum[i][j - 1] + arr[i][j];

	while (m--) {
		int command;
		cin >> command;
		if (command) {
			int x1, y1, x2, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			
			int ans = 0;
			for (int i = y1; i <= y2; i++)
				ans += sum[i][x2] - sum[i][x1 - 1];
			cout << ans << endl;
		}
		else {
			int x, y, value;
			cin >> y >> x >> value;
			arr[y][x] = value;
			for (int i = x; i <= n; i++)
				sum[y][i] = sum[y][i - 1] + arr[y][i];
		}
	}
	
	return 0;
}