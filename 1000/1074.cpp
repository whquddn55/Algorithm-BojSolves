#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int get(int y, int x, int n, int num) {
	if (y == r && x == c)
		return num;

	int t1 = 1;
	int t2 = 1;
	for (int i = 0; i < n; i++) {
		t1 *= 2;
		t2 *= 4;
	}
	t2 /= 4;
	
	if (c < x + t1 / 2 && r < y + t1 / 2)
		return get(y, x, n - 1, num);
	else if (c >= x + t1 / 2 && r < y + t1 / 2)
		return get(y, x + (t1 / 2), n - 1, num + t2);
	else if (c < x + t1 / 2 && r >= y + t1 / 2)
		return get(y + (t1 / 2), x, n - 1, num + t2 * 2);
	else
		return get(y + (t1 / 2), x + (t1 / 2), n - 1, num + t2 * 3);
}

int main() {
	cin >> n >> r >> c;

	cout << get(0, 0, n, 0) << endl;

	return 0;
}