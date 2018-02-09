#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<vector<int> > arr;
vector<vector<bool> > same;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	same.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(5);
		same[i].resize(n);
		for (int j = 0; j < 5; j++) 
			scanf("%d", &arr[i][j]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = i + 1; k < n; k++) {
				if (arr[i][j] == arr[k][j]) {
					same[i][k] = true;
					same[k][i] = true;
				}
			}
		}
	}

	int maxValue = 0;
	int result = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (same[i][j])
				cnt++;

		if (maxValue < cnt) {
			maxValue = cnt;
			result = i + 1;
		}
	}
	printf("%d\n", result);


	return 0;
}