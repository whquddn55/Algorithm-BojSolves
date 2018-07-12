#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

int n;
bool f[MAX_N][MAX_N];
int f2[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'Y')
				f[i][j] = true;
			else
				f[i][j] = false;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (f[i][j])
				f2[i]++;
			else
				for (int k = 0; k < n; k++)
					if (f[i][k] && f[j][k]) {
						f2[i]++;
						break;
					}
		}
	cout << *max_element(f2, f2 + n) << endl;

	return 0;
}