#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
set<int> s;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		s.insert(t);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		printf("%d\n", s.count(t));
	}
	

	return 0;

}