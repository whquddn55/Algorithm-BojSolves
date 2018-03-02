#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int s, c;
vector<int> arr;

bool dicide(int m) {
	int cnt = 0;
	for (int i = 0; i < s; i++)
		cnt += arr[i] / m;

	return cnt >= c;
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;

	while (left < right) {
		int mid = (left + right) / 2;

		if (dicide(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	return right;
}

int main() {
	scanf("%d %d", &s, &c);
	arr.resize(s);
	int maxValue = 0;
	for (int i = 0; i < s; i++) {
		scanf("%d", &arr[i]);
		maxValue = max(maxValue, arr[i]);
	}

	int value = binarySearch(1, maxValue);
	ll ret = 0;
	int cnt = 0;
	for (int i = 0; i < s; i++) {
		ret += (arr[i] % value);
		if (cnt + (arr[i] / value) > c) {
			ret += arr[i] - value * (c - cnt);
			break;
		}
		cnt += arr[i] / value;
	}


	printf("%lld\n", ret);

	return 0;
}