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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100000

string str[2];
int t[2];

int divisor[] = { 36000, 3600, 0, 600, 60, 0, 10, 1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < 2; i++) {
		cin >> str[i];
		for (int j = 0; j < 8; j++) 
			t[i] += str[i][j] * divisor[j];
	}

	if (t[0] >= t[1])
		t[1] += 3600 * 24;

	int diff = t[1] - t[0];
	for (int i = 0; i < 8; i++) {
		if (i == 2 || i == 5)
			cout << ":";
		else {
			cout << diff / divisor[i];
			diff %= divisor[i];
		}
	}

	return 0;
}
