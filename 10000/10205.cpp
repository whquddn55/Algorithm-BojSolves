#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		int h;
		scanf("%d", &h);
		string s;
		cin >> s;

		for (const auto& e : s)
			if (e == 'b')
				h -= 1;
			else
				h += 1;
		printf("Data Set %d:\n%d\n\n", i, h);
	}

	return 0;
}