#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

bool decide(int mid) { // mid원으로 예산을 배정했을 때 m원 이하으로 나오는가?
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += (arr[i] > mid ? mid : arr[i]);
	return m >= sum;
}

int binarySearch(int maxV) {
	int left = 0, right = maxV;
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (decide(mid)) 
			left = mid + 1;
		else
			right = mid - 1;
	}

	return right;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);

	int maxV = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxV = max(maxV, arr[i]);
	}
	scanf("%d", &m);

	printf("%d\n", binarySearch(maxV));

	return 0;
}