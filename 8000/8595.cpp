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

#define MAX_N 100000

int n;
string str;

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> str;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (!isalpha(str[i]))
			temp = temp * 10 + str[i] - '0';
		else if (temp) {
			ans += temp;
			temp = 0;
		}
	}
	cout << ans + temp << endl;

	return 0;
}
