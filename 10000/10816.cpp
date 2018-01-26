#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

vector<int> arr;
int n, m;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int element;
		scanf("%d", &element);
		if (binary_search(arr.begin(), arr.end(), element)) 
			printf("%d ", upper_bound(arr.begin(), arr.end(), element) - lower_bound(arr.begin(), arr.end(), element));
		else 
			printf("0 ");
	}
	printf("\n");

	return 0;
}