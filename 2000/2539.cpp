#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int height, n;
int k, t;
vector<pii> arr;

bool decide(int mid) { // mid짜리 크기로 k개 이하로 구성이 가능한가?
	int cnt = 1;
	int nextBoundary = arr[0].first + mid - 1;
	for (int i = 1; i < t; i++) {
		if (arr[i].first <= nextBoundary)
			continue;
		cnt++;
		nextBoundary = arr[i].first + mid - 1;
	}

	return cnt <= k;
}

int binarySearch(int minValue, int maxValue) {
	int l = minValue, r = maxValue;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (decide(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}

	return l;
}

int main() {
	scanf("%d %d %d %d", &height, &n, &k, &t);
	arr.resize(t);
	int minValue = 0;
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &arr[i].second, &arr[i].first);
		minValue = max(minValue, arr[i].second);
	}

	sort(arr.begin(), arr.end());
	printf("%d\n", binarySearch(minValue, height));

	return 0;
}