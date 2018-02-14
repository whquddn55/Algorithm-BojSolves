#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int x, y, d, t;

int main() {
	scanf("%d %d %d %d", &x, &y, &d, &t);
	double rt = sqrt(x * x + y * y);
	int c = rt / d;
	printf("%.9lf\n", min({ rt, (rt - c * d) + c * t, c ? (double)c * t + t : min(t * 2.0, t + d - rt) }));
	return 0;
}