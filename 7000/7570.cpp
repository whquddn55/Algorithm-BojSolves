#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n + 1, 0);

	int result = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		arr[temp] = arr[temp - 1] + 1;
		result = max(result, arr[temp]);
	}

	printf("%d\n", n - result);

	return 0;
}