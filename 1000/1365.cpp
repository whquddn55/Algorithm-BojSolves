#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
vector<int> lis;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	lis.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (lis[lis.size() - 1] < arr[i]) 
			lis.push_back(arr[i]);
		else 
			lis[lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin()] = arr[i];
	}

	printf("%d\n", n - lis.size());
	
	return 0;
}