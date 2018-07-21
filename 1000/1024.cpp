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

#define MAX_N 50

int n, l;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> l;

	for (int i = l; i <= 100; i++) {
		if (i % 2) {
			if (n % i == 0) {
				int start = n / i - (i / 2);
				if (start < 0)
					continue;
				for (int j = 0; j < i; j++)
					cout << start + j << ' ';
				cout << endl;
				return 0;
			}
		}
		else {
			if ((n - i / 2) % i == 0) {
				int start = (n - i / 2) / i - (i - 1) / 2;
				if (start < 0)
					continue;
				for (int j = 0; j < i; j++)
					cout << start + j << ' ';
				cout << endl;
				return 0;
			}
		}

	}
	cout << -1 << endl;
	

	return 0;
}
