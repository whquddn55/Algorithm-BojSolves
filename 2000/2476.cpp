#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr(3);

int main() {
	scanf("%d", &n);
	int result = 0;
	while (n--) {
		for (int i = 0; i < 3; i++)
			scanf("%d", &arr[i]);

		int temp = 0;
		if (arr[0] == arr[1] && arr[1] == arr[2])
			temp = 10000 + 1000 * arr[0];
		else if (arr[0] == arr[1])
			temp = 1000 + 100 * arr[0];
		else if (arr[1] == arr[2])
			temp = 1000 + 100 * arr[1];
		else if (arr[2] == arr[0])
			temp = 1000 + 100 * arr[2];
		else
			temp = max({ arr[0], arr[1], arr[2] }) * 100;

		result = max(result, temp);
	}

	printf("%d\n", result);

	return 0;
}