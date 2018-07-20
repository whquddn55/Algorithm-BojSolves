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

int n;
vector<int> number;

void makeNumber(int num) {
	if (num >= 1000000)
		return;
	num *= 10;
	num += 4;
	number.push_back(num);
	makeNumber(num);

	num -= 4;
	num += 7;
	number.push_back(num);
	makeNumber(num);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	makeNumber(0);
	sort(number.begin(), number.end());

	cin >> n;
	cout << *(--upper_bound(number.begin(), number.end(), n)) << endl;

	return 0;
}
