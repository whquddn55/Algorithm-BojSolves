#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, l;
vector<pii> sticks;

int main() {
	scanf("%d %d", &n, &l);
	sticks.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &sticks[i].first, &sticks[i].second);

	int result = 0;
	for (int i = 1; i < n; i++)
		if (sticks[i].second != sticks[i - 1].second)
			result = max(result, (l - sticks[i].first - sticks[i - 1].first) / 2);

	printf("%d\n", result);

	return 0;
}