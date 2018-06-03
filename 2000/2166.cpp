#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 10000

struct Point {
	int x, y;

	Point(int x = 0, int y = 0)
		: x(x), y(y) { }
};

int n;
Point point[MAX_N];

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> point[i].x >> point[i].y;

	Point here1(point[0]);
	for (int i = 1; i < n - 1; i++) {
		Point here2(point[i]);
		Point next(point[i + 1]);
		ll value = (ll)(here2.x - here1.x) * (next.y - here1.y) - (ll)(here2.y - here1.y) * (next.x - here1.x);
		ans += value;
	}
	if (ans < 0)
		ans = -ans;
	cout << ans / 2 << (ans % 2 ? ".5" : ".0") << endl;

	return 0;
}