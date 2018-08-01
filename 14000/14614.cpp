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

#define MAX_N 500

int a, b;
string c;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> a >> b >> c;
	if ((c.back() - '0') % 2)
		cout << (a ^ b) << endl;
	else
		cout << a << endl;


	return 0;
}