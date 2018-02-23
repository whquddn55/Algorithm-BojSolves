#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
vector<int> result;
vector<bool> visited;

int main() {
	scanf("%d %d", &n, &m);

	result.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 1; i <= n; i++)
		result[i] = i;
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		result[from]++;
		result[to]--;
	}
	for (int i = 1; i <= n; i++)
		if (visited[result[i]]) {
			printf("-1\n");
			return 0;
		}
		else 
			visited[result[i]] = true;
		

	for (int i = 1; i <= n; i++)
		printf("%d ", result[i]);
	printf("\n");

	return 0;

}