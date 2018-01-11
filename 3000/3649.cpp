#include <bits/stdc++.h>
using namespace std;

int x, n;
vector<int> legos;

// legos[mid]가 x보다 작은가?
bool decide(int mid) {
	return legos[mid] < x;
}

int binarySearch(int minIndex, int maxIndex) {
	int left = minIndex, right = maxIndex;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (decide(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (x != legos[left])
		return -1;
	return left;
}

int main() {
	while (scanf("%d", &x) != EOF) {
		x *= 10000000;
		cin >> n;

		legos.clear();
		legos.resize(n);
		for (int i = 0; i < n; i++)
			cin >> legos[i];

		sort(legos.begin(), legos.end());
		bool check = false;
		for (int i = 0; i < legos.size(); i++) {
			if (x / 2 < legos[i]) {
				cout << "danger" << endl;
				check = true;
				break;
			}
			x -= legos[i];
			int result = binarySearch(i + 1, legos.size() - 1);
			x += legos[i];
			if (result != -1) {
				cout << "yes " << legos[i] << ' ' << legos[result] << endl;
				check = true;
				break;
			}
		}

		if (!check) 
			cout << "danger" << endl;

	}

	return 0;
}