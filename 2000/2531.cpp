#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, d, k, c;
vector<int> arr;

int main() {
	scanf("%d %d %d %d", &n, &d, &k, &c);
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	
	vector<int> visited(d + 1, false);
	int result = 0;
	for (int j = 0; j < k; j++) {
		if (!visited[arr[j]]) 
			result++;
		visited[arr[j]]++;
	}
	
	int cnt = result;
	if (!visited[c])
		result++;

	for (int i = 1; i < n; i++) {
		visited[arr[i - 1]]--;
		if (!visited[arr[i - 1]])
			cnt--;
		if (!visited[arr[(i - 1 + k) % n]]) 
			cnt++;
		visited[arr[(i - 1 + k) % n]]++;

		result = max(result, visited[c] ? cnt : (cnt + 1));

	}

	printf("%d\n", result);

	return 0;
}