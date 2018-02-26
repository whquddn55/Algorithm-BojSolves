#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
vector<int> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		printf("%d ", binary_search(arr.begin(), arr.end(), t));
	}

	return 0;

}
