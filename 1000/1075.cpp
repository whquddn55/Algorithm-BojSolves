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

#define MAX_N 51

int n, f;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> f;
	n = n / 100 * 100;
	for (int i = 0; i < 99; i++) 
		if ((n + i) % f == 0) {
			if (i < 10)
				cout << 0;
			cout << i << endl;
			break;
		}
	

	return 0;
}
