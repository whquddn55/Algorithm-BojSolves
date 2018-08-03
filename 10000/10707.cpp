#include <bits/stdc++.h>
#include <unordered_set>
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

#define MAX_N 10000
#define MAX_K 1000000

int a, b, c, d, p;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> a >> b >> c >> d >> p;

	cout << min(p * a, b + max(0, p - c) * d) << endl;

	return 0;
}