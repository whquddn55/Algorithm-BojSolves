#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);

		int cnt = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if ((i*i + j * j + m) % (i*j) == 0)
					cnt++;

		printf("%d\n", cnt);
	}


	return 0;
}