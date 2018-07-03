#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

int sum = 0;
int minValue = INF;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < 7; i++) {
		int t;
		cin >> t;
		if (t % 2) {
			sum += t;
			minValue = min(minValue, t);
		}
	}
	if (sum == 0)
		cout << -1 << endl;
	else
		cout << sum << endl << minValue << endl;
	
	return 0;
}
