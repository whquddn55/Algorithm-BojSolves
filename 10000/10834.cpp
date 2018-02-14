#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<tuple<int,int,int> > arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);

	bool result1 = false;
	int result2 = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &get<0>(arr[i]), &get<1>(arr[i]), &get<2>(arr[i]));
		if (get<2>(arr[i]))
			result1 = !result1;
		result2 /= get<0>(arr[i]);
		result2 *= get<1>(arr[i]);
	}
	printf("%d %d\n", result1, result2);

	return 0;
}