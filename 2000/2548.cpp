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
	printf("%d\n", arr[(n - 1) / 2]);


	return 0;
}