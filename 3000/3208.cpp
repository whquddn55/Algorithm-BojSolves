#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	if (n <= m)
		cout << n * 2 - 2 << endl;
	else
		cout << m * 2 - 1 << endl;
	
	return 0;
}