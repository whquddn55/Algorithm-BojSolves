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

int n, m;
vector<int> arr;

bool dicide(int mid) {
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > mid) {
			sum = arr[i];
			cnt++;
		}
		else 
			sum += arr[i];
		
	}
	return (cnt + (sum != 0) ) <= m;
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (dicide(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(n);
	int minValue = 0, maxValue = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		minValue = max(minValue, arr[i]);
		maxValue += arr[i];
	}

	int result = binarySearch(minValue, maxValue);
	printf("%d\n", result);

	int sum = 0;
	int sz = 0;
	vector<int> pr;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > result) {
			pr.push_back(sz);
			sum = arr[i];
			sz = 1;
		}
		else {
			sum += arr[i];
			sz++;
		}
	}
	if (sz) 
		pr.push_back(sz);
	
	if (pr.size() != m) {
		int size = pr.size();
		for (int i = 0; i < pr.size() && pr.size() != m; i++)
			if (pr[i] != 1) {
				while ((pr[i] != 1) && pr.size() != m) {
					pr.insert(pr.begin() + i + 1, 1);
					pr[i]--;
				}
			}
	}

	for (int i = 0; i < m; i++)
		printf("%d ", pr[i]);


	printf("\n");

	return 0;
}