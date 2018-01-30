#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	vector<int> arr(21);
	for (int i = 1; i < 21; i++)
		arr[i] = i;

	for (int i = 0; i < 10; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		reverse(arr.begin() + a, arr.begin() + b + 1);
	}

	for (int i = 1; i < 21; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}