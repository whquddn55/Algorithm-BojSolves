#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100000

struct Point {
	int x, y;
	
	Point(int x = 0, int y = 0)
		: x(x), y(y) { }
};

Point point[3];

int ccw(Point a, Point b, Point c) {
	ll value = (ll)(b.x - a.x) * (c.y - a.y) - (ll)(b.y - a.y) * (c.x - a.x);
	if (value == 0)
		return 0; // 일직선
	return value > 0 ? 1 : -1; // 1 : 반 시계 방향 -1 : 시계 방향
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < 3; i++)
		cin >> point[i].x >> point[i].y;
	cout << ccw(point[0], point[1], point[2]);
	
	return 0;
}