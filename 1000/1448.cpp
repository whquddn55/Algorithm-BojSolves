#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n;
vector<int> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	for (int i = n - 1; i > 1; i--) {
		if (arr[i] < (arr[i - 1] + arr[i - 2])) {
			printf("%d\n", arr[i] + arr[i - 1] + arr[i - 2]);
			return 0;
		}
	}
	printf("-1\n");

	return 0;
}