#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

ll n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (cin >> n) {
		ll l = (n + 8) / 9, h = (n + 1) / 2;
		bool who = true;

		while (true) {
			if (l <= 1 && h >= 1) {
				cout << (who ? "Baekjoon wins." : "Donghyuk wins.") << endl;
				break;
			}
			if (who) {
				l = (l + 1) / 2;
				h = (h + 8) / 9;
				who = false;
			}
			else {
				l = (l + 8) / 9;
				h = (h + 1) / 2;
				who = true;
			}
		}
	}


	return 0;
}
