#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
vector<vector<int> > arr;

int main() {
	scanf("%d %d", &n, &k);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		arr[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}

	bool result = false;
	for (int i = 0; i <= arr[0].size() - k; i++) {
		vector<int> toCheck;
		for (int j = i; j < i + k; j++) 
			toCheck.push_back(arr[0][j]);

		bool flag = true; // 현재 문자열이 통과되었는가?
		for (int j = 1; (j < n) && flag; j++) {
			bool check = false; // 현재 문자열에서 바이러스 코드를 찾았는가?
			for (int l = 0; l <= arr[j].size() - k; l++) {
				check = true;
				for (int m = 0; m < k; m++) {
					if (toCheck[m] != arr[j][l + m]) {
						check = false;
						break;
					}
				}
				if (check)
					break;

				check = true;
				for (int m = 0; m < k; m++) {
					if (toCheck[k - m - 1] != arr[j][l + m]) {
						check = false;
						break;
					}
				}
				if (check)
					break;
			}
			if (!check)
				flag = false;
		}
		if (flag) {
			result = true;
			break;
		}
	}

	printf(result ? "YES\n" : "NO\n");
	

	return 0;
}