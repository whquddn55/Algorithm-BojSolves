#include <iostream>
#include <cmath>
using namespace std;

bool isInBound(int x1, int y1, int x, int y, int r) {
	return sqrt(pow(x - x1, 2) + pow(y - y1, 2)) < r;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		int result = 0;
		while (n--) {
			int x, y, r;
			cin >> x >> y >> r;

			if (isInBound(x1, y1, x, y, r) && isInBound(x2, y2, x, y, r))
				continue;
			else if (isInBound(x1, y1, x, y, r) || isInBound(x2, y2, x, y, r))
				result++;
		}
		cout << result << endl;
	}

	return 0;
}