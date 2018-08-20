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

#define MAX_N 6561

int n;
char arr[MAX_N][MAX_N];

void get(int y, int x, int d) {
	if (d == 1) {
		arr[y][x] = '*';
		return;
	}
	get(y, x, d / 3);
	get(y, x + d / 3, d / 3);
	get(y, x + d / 3 * 2, d / 3); 
	get(y + d / 3, x, d / 3);
	get(y + d / 3, x + d / 3 * 2, d / 3); 
	get(y + d / 3 * 2, x, d / 3);
	get(y + d / 3 * 2, x + d / 3, d / 3);
	get(y + d / 3 * 2, x + d / 3 * 2, d / 3);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < MAX_N; i++)
		fill_n(arr[i], MAX_N, ' ');

	cin >> n;
	get(0, 0, n);
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
	
	return 0;
}