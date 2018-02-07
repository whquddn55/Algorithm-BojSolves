#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int temp1 = 1, temp2 = 1;
	int result = 1;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			temp1++;
			temp2 = 1;
		}
		else if (arr[i] > arr[i + 1]) {
			temp2++;
			temp1 = 1;
		}
		else {
			temp1++;
			temp2++;
		}
		result = max({ result, temp1, temp2 });
	}

	printf("%d\n", result);
	
	return 0;
}