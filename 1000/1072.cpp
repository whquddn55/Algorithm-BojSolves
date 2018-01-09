#include <bits/stdc++.h>
using namespace std;

long long x, y;
int winRate;

// mid판 이겨서 값이 변하는 가?
bool decision(int mid) {
	int newRate = (y + mid) * 100 / (x + mid);

 	return newRate != winRate;
}

int binarySearch(long maxValue) {
	long left = 1, right = maxValue;

	while (left <= right) {
		long mid = (right + left) / 2;
		if (decision(mid)) 
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}

int main() {
	while (scanf("%lld %lld", &x, &y) != EOF) {
		winRate = (y * 100) / x;
		if (winRate == 100 || winRate == 99) 
			cout << -1 << endl;
		else
			cout << binarySearch(x) << endl;
	}

	return 0;
}