#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<int> > arr;
vector<int> check;

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
		sort(arr[i].begin(), arr[i].end());
	}

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for (int i = 0; i < n; i++)
		pq.emplace(arr[i][0], i);

	int maxValue = 0;
	for (int i = 0; i < n; i++)
		maxValue = max(maxValue, arr[i][0]);
	
	int result = INT_MAX;
	check.resize(n, 0);
	while (pq.size() == n) {
		pii t = pq.top();
		result = min(result, maxValue - t.first);
		check[t.second]++;
		if (check[t.second] >= m) 
			break;
		else {
			pq.emplace(arr[t.second][check[t.second]], t.second);
			pq.pop();
			maxValue = max(maxValue, arr[t.second][check[t.second]]);
		}
	}

	printf("%d\n", result);

	

	return 0;
}