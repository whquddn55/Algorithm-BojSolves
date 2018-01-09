#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> woods;

// mid미터로 잘랐을 때 m이상 가능한가
bool decision(int mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) 
		sum += (woods[i] - mid) > 0 ? (woods[i] - mid) : 0;
	
	return sum >= m;
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
	cin >> n >> m;

	woods.resize(n);
	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		cin >> woods[i];
		maxValue = max(maxValue, woods[i]);
	}

	cout << binarySearch(maxValue) << endl;

	return 0;
}