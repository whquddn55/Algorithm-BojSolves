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

#define MAX_N 500000

int n, k;
int value[10000];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	value[1] = 1;
	for (int i = 2; i < 10000; i++)
		value[i] = i * (i - 1) / 2 + 1;

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;

		pii p1, p2;
		int i;
		for (i = 1; i < 10000; i++)
			if (a < value[i])
				break;
		i--;
		p1 = { a - value[i] + 1, i - (a - value[i])};

		for (i = 1; i < 10000; i++)
			if (b < value[i])
				break;
		i--;
		p2 = { b - value[i] + 1, i - (b - value[i])};

		pii p3 = { p1.first + p2.first, p1.second + p2.second };
		cout << (value[p3.first + p3.second - 1] + (p3.first - 1)) << endl;
	}

	return 0;
}