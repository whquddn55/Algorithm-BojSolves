#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n;
set<int> arr;

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		arr.clear();

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			arr.insert(temp);
		}

		int cnt = 0;
		for (set<int>::iterator it1 = arr.begin(); it1 != arr.end(); ++it1) {
			for (set<int>::iterator it2 = next(it1); it2 != arr.end(); ++it2) {
				int gap = *it2 - *it1;
				if (arr.count(*it2 + gap))
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}