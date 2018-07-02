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

int n, d;
int numOfParent[MAX_N];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		numOfParent[t]++;
	}

	for (int i = 0; i <= n; i++) {
		if (numOfParent[i] > d) {
			while (numOfParent[i] > d) {
				int t = numOfParent[i] / d;
				ans += t;
				numOfParent[i] %= d;
				numOfParent[i] += t;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
