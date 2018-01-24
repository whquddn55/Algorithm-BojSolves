#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;

int main() {
	scanf("%d %d", &n, &k);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];

	int result = sum;
	for (int i = 1; i <= (n - k); i++) {
		sum -= arr[i - 1];
		sum += arr[i + k - 1];
		result = max(result, sum);
	}

	printf("%d\n", result);
		 

	return 0;
}