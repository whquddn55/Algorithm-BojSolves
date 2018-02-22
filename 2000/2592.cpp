#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

vector<int> arr(10);
vector<int> num(1001, 0);


int main() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		num[arr[i]]++;
	}

	int value = 0;
	int maxValue = -1;
	for (int i = 0; i < 10; i++)
		if (num[arr[i]] > maxValue) {
			maxValue = num[arr[i]];
			value = arr[i];
		}
	printf("%d\n%d\n", sum / 10, value);

	return 0;

}
