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

#define MAX_N 10

int k;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
		cout << 1;
	for (int i = 0; i < k - 1; i++)
		cout << 0;
		
	return 0;
}
