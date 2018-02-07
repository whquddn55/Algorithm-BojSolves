#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
stack<int> arr;
vector<int> result;

int main() {
	scanf("%d", &n);
	result.resize(n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr.push(temp);
	}

	priority_queue<pii, vector<pii>, greater<pii> > get;
	get.emplace(arr.top(), n - 1);
	arr.pop();
	int hereIdx = n;
	while (!arr.empty()) {
		int here = arr.top();
		arr.pop();
		hereIdx--;

		while (get.top().first < here && !get.empty()) {
			int idx = get.top().second;
			get.pop();

			result[idx] = hereIdx;
		}
		get.emplace(here, hereIdx - 1);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);
	printf("\n");

	
	return 0;
}