#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m, k;
vector<vector<char>> mat;
vector<int> cntOfZero;

int main() {
	scanf("%d %d", &n, &m);
	mat.resize(n);
	cntOfZero.resize(n);
	for (int i = 0; i < n; i++)  {
		mat[i].resize(m);
		for (int j = 0; j < m; j++) {
			scanf(" %c", &mat[i][j]);
			if (mat[i][j] == '0')
				cntOfZero[i]++;
		}
	}

	scanf("%d", &k);

	int result = 0;
	for (int i = 0; i < n; i++) {
		if ((cntOfZero[i] <= k) && ((k - cntOfZero[i]) % 2 == 0)) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				bool check = true;
				for (int k = 0; k < m; k++) 
					if (mat[i][k] != mat[j][k]) {
						check = false;
						break;
					}
				if (check)
					cnt++;
			}
			result = max(result, cnt);
		}
	}
	printf("%d\n", result);
	

	return 0;
}