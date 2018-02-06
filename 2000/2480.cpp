#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> arr(3);

int main() {
	for (int i = 0; i < 3; i++) 
		scanf("%d", &arr[i]);
	
	int result = 0;
	if (arr[0] == arr[1] && arr[1] == arr[2])
		result = 10000 + 1000 * arr[0];
	else if (arr[0] == arr[1])
		result = 1000 + 100 * arr[0];
	else if (arr[1] == arr[2])
		result = 1000 + 100 * arr[1];
	else if (arr[2] == arr[0])
		result = 1000 + 100 * arr[2];
	else
		result = max({ arr[0], arr[1], arr[2] }) * 100;

	printf("%d\n", result);

	return 0;
}