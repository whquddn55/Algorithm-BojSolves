#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n;
vector<int> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);
    
    long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
        sum += arr[i];
    }

	sort(arr.begin(), arr.end());
	printf("%d ", arr[(n - 1) / 2]);
	printf("%d\n", (sum % n > (n + 1) / 2) ? sum / n + 1 : sum / n);

	return 0;
}