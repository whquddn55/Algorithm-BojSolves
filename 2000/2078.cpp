#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 2001

int a, b;
int l, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> a >> b;
	while (true) {
		if (a == 1) {
			r += b - 1;
			if (b == 1) 
				l += a - 1;
			break;
		}
		if (b == 1) {
			l += a - 1;
			break;
		}
		if (a > b) {
			a = a - b;
			l++;
		}
		else {
			b = b - a;
			r++;
		}
	}
	cout << l << ' ' << r << endl;

	return 0;
}