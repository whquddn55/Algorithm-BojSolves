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

	for (int i = 0; i < n; i = upper_bound(arr.begin(), arr.end(), arr[i]) - arr.begin()) {
		printf("%d ", arr[i]);
	}

	return 0;
}