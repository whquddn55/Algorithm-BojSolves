#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

struct Point {
	int y, x;
	Point() { }
	Point(int y, int x)
		:y(y), x(x) { }
};

struct Rectangle {
	Point lb, rt;
	Rectangle() { }
};

int main() {
	int tc = 4;
	while (tc--) {
		Rectangle r1, r2;
		scanf("%d %d %d %d %d %d %d %d", &r1.lb.x, &r1.lb.y, &r1.rt.x, &r1.rt.y, &r2.lb.x, &r2.lb.y, &r2.rt.x, &r2.rt.y);

		if ((r1.rt.x == r2.lb.x && r1.rt.y == r2.lb.y) || (r1.rt.x == r2.lb.x && r1.lb.y == r2.rt.y) || (r1.lb.x == r2.rt.x && r1.lb.y == r2.rt.y) || (r1.lb.x == r2.rt.x && r1.rt.y == r2.lb.y))
			printf("c\n");
		else if (r1.rt.x == r2.lb.x || r1.lb.y == r2.rt.y || r1.lb.x == r2.rt.x || r1.rt.y == r2.lb.y)
			printf("b\n");
		else if (r1.rt.x < r2.lb.x || r1.lb.y > r2.rt.y || r1.lb.x > r2.rt.x || r1.rt.y < r2.lb.y)
			printf("d\n");
		else
			printf("a\n");
	}


	return 0;
}