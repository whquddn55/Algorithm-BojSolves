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

	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == (arr[(i + 1) % n] - 1)) {
			temp1++;
			temp2++;

		}
		else if ((arr[i] == n) && (arr[(i + 1) % n] == 1)) {
			temp1++;
			temp2++;
		}
		else
			temp2 = 0;
	}

	if (temp2 == 0) {
		int r1, r2, r3;
		int temp2 = 0;
		int temp1 = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] == (arr[(i + 1) % n] + 1) || (arr[i] == 1 && arr[(i + 1) % n] == n)) {
				temp1++;
				temp2++;
			}
			else if (i == n - 1)
				temp2++;
			else
				temp2 = 0;
		}
		if (temp1 > n)
			temp1 = n;

		r1 = temp2;
		r2 = 1;
		r3 = temp1;

		printf("%d\n%d %d\n%d\n", arr[(n - temp2 - 1) == -1 ? 0 : (n - temp2 - 1)], r2, r3, r1);
	}
	else {
		int r1, r2, r3;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] == arr[(i + 1) % n] - 1)
				cnt++;
		}

		r1 = temp2;
		r2 = temp1 + 2;
		r3 = n;
		printf("%d\n%d %d\n%d\n", (arr[(r2 - r1) - 1]), r2, r3, r1);
	}


	return 0;
}