#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dist = sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
		int len1 = r1 + r2;
		int len2 = r2 - r1 > 0 ? r2 - r1 : r1 - r2;

		int result;
		if (dist == 0) {
			if (len2 == 0)
				result = -1;
			else
				result = 0;
		}
		else {
			if (dist == len1)
				result = 1;
			else if (dist > len1)
				result = 0;
			else {
				if (dist == len2)
					result = 1;
				else if (dist < len2)
					result = 0;
				else
					result = 2;
			}
		}
		cout << result << endl;
	}
}