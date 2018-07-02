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

#define MAX_N 100001

int sum;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> sum;
	for (int i = 0; i < 9;  i++) {
		int t;
		cin >> t;
		sum -= t;
	}
	cout << sum << endl;
		
	return 0;
}
