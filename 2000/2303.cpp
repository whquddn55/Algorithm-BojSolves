#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<vector<int> > arr;
vector<int> sum;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	sum.resize(n, 0);
	for (int i = 0; i < n; i++) {
		arr[i].resize(5);
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);

		vector<int>& temp = arr[i];
		sum[i] = max({ (temp[0] + temp[1] + temp[2]) % 10,
			(temp[0] + temp[1] + temp[3]) % 10,
			(temp[0] + temp[1] + temp[4]) % 10,
			(temp[0] + temp[2] + temp[3]) % 10,
			(temp[0] + temp[2] + temp[4]) % 10,
			(temp[0] + temp[3] + temp[4]) % 10,
			(temp[1] + temp[2] + temp[3]) % 10,
			(temp[1] + temp[2] + temp[4]) % 10,
			(temp[1] + temp[3] + temp[4]) % 10,
			(temp[2] + temp[3] + temp[4]) % 10});
	}
	int temp = -1;
	int result;
	for (int i = n - 1; i >= 0; i--) {
		if (temp < sum[i]) {
			temp = sum[i];
			result = i + 1;
		}
	}
	printf("%d\n", result);


	return 0;
}