#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

struct Data {
	int x, y;

	Data() { }
	Data(int x, int y)
		: x(x), y(y) { }

	bool operator<(const Data& other) {
		return (y == other.y) ? (x < other.x) : (y < other.y);
	}
};

int n, m, t, k;
vector<Data> dots;

int main() {
	scanf("%d %d %d %d", &n, &m, &t, &k);
	dots.resize(t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &dots[i].x, &dots[i].y);
		dots[i].y = m - dots[i].y;
	}
	sort(dots.begin(), dots.end());

	int result = 0;
	Data resultDot;

	for (int i = 0; i < t; i++) {
		for (int l = 0; l <= k; l++) {
			int rtY = dots[i].y;
			int lbX = dots[i].x - l;
			int lbY = dots[i].y + k;
			int rtX = dots[i].x + k - l;
			if (lbX < 0)
				break;
			if (rtX > n)
				continue;
			if (lbY > m) {
				rtY = m - k;
				lbY = m;
			}
			
			int cnt = 0;
			for (int j = i; j < t; j++) {
				if (dots[j].y <= lbY && dots[j].x >= lbX && dots[j].x <= rtX)
					cnt++;
				if (dots[j].y > lbY)
					break;
			}
			if (cnt > result) {
				result = cnt;
				resultDot.x = lbX;
				resultDot.y = rtY;
			}
		}

	}

	printf("%d %d\n%d\n", resultDot.x, m - resultDot.y, result);


	return 0;
}