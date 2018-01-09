#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> houses;

// mid거리이상 떨어지도록 설치가 가능한가
bool decision(int mid) {
	int index = 1;
	int lastInstalledIndex = 0;
	int remainRouters = c - 1;
	while (index < n && remainRouters != 0) {
		if (houses[index] - houses[lastInstalledIndex] >= mid) {
			remainRouters--;
			lastInstalledIndex = index;
			
		}
		index++;
	}
	return (remainRouters == 0);
}

int binarySearch(int maxValue) {
	int left = 1, right = maxValue;

	while (left <= right) {
		int mid = (right + left) / 2;
		if (decision(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	return right;
}

int main() {
	cin >> n >> c;

	houses.resize(n);
	for (int i = 0; i < n; i++)
		cin >> houses[i];

	sort(houses.begin(), houses.end());

	cout << binarySearch(houses[n - 1]) << endl;

	return 0;
}