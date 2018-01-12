#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> jewerly;

// 질투심 m으로 n명이하에게 나누어 줄 수 있는가?
bool decide(int mid) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += jewerly[i] / mid;
		if (jewerly[i] % mid != 0)
			cnt++;
	}

	return cnt <= n;
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (decide(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}

int main() {
	cin >> n >> m;

	jewerly.resize(m);
	int maxValue = 0;
	for (int i = 0; i < m; i++) {
		cin >> jewerly[i];
		maxValue = max(maxValue, jewerly[i]);
	}

	cout << binarySearch(1, maxValue) << endl;

	return 0;
}