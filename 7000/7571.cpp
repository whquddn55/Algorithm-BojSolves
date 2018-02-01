#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> r;
vector<int> c;

int main() {
	scanf("%d %d", &n, &m);
	r.resize(m);
	c.resize(m);
	for (int i = 0; i < m; i++) 
		scanf("%d %d", &r[i], &c[i]);
	
	sort(r.begin(), r.end());
	sort(c.begin(), c.end());

	int midR = r[m / 2];
	int midC = c[m / 2];

	int result = 0;
	for (int i = 0; i < m; i++)
		result += abs(midR - r[i]) + abs(midC - c[i]);

	printf("%d\n", result);

	return 0;
}