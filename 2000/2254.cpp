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

int n;
Point prizon;
Point point[MAX_N];

int ans = 0;

int ccw(Point a, Point b, Point c) {
	ll value = (ll)(b.x - a.x) * (c.y - a.y) - (ll)(b.y - a.y) * (c.x - a.x);
	if (value == 0)
		return 0; // 일직선
	return value > 0 ? 1 : -1; // 1 : 반 시계 방향 -1 : 시계 방향
}

vector<pair<Point, int>> getConvexHull() {
	int lob = 0;
	for (int i = 0; i < n; i++)
		if (point[lob].x > point[i].x || (point[lob].x == point[i].x && point[lob].y > point[i].y))
			lob = i;
	swap(point[lob], point[0]);

	sort(point + 1, point + n, [](Point& a, Point& b)->bool {
		int val = ccw(point[0], a, b);
		if (val > 0) return true;
		if (val < 0) return false;
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});

	vector<pair<Point, int>>  st;
	for (int i = 0; i < n; i++) {
		while (st.size() >= 2 && ccw(st[st.size() - 2].first, st.back().first, point[i]) <= 0)
			st.pop_back();
		st.emplace_back(point[i], i);
	}
	return st;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> prizon.x >> prizon.y;
	for (int i = 0; i < n; i++)
		cin >> point[i].x >> point[i].y;

	int cnt = 0;
	while (true) {
		if (n == 0)
			break;
		vector<pair<Point, int>>  result = getConvexHull();
		if (result.size() <= 2)
			break;

		int value = ccw(prizon, result[0].first, result[1].first);
		bool check = true;
		for (int i = 0; i < result.size() - 1; i++) {
			int v = ccw(prizon, result[i].first, result[i + 1].first);
			if (v != value) {
				check = false;
				break;
			}
		}

		for (int i = result.size() - 1; i >= 0; i--) {
			n--;
			swap(point[n], point[result[i].second]);
		}

		if (check)
			ans++;
		else
			break;
	}
	cout << ans << endl;

	return 0;
}