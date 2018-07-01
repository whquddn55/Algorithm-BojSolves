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

int a, b;
int diff;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	
	while (tc--) {
		cin >> a >> b;
		diff = b - a;
		int k = (int)sqrt(diff);

		cout << k * 2 - 1 + (diff - k * k + (k - 1)) / k << endl;
	}

	return 0;
}