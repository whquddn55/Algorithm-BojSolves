#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n;
vector<int> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	int maxValue = 0;
	int minValue = INT_MAX;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxValue = max(maxValue, arr[i]);
		minValue = min(minValue, arr[i]);
	}

	printf("%d\n", maxValue * minValue);

	

	return 0;
}