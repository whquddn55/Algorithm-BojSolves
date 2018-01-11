#include <bits/stdc++.h>
using namespace std;

int n, k;

// mid보다 작은 숫자들의 개수가 k보다 작은가?
bool decide(int mid) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += min(mid / i, n);

	return k > cnt;
}

int binarySearch(int maxValue) {
	int left = 1, right = maxValue;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (decide(mid))
			left = mid + 1;
		else 
			right = mid - 1;
	} 

	return left;
}

int main() {
	cin >> n >> k;

	cout << binarySearch(k) << endl;

	return 0;
}