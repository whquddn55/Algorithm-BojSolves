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

#define MAX_N 11

int n;
int ans[MAX_N];
bool checked[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		t++;
		for (int j = 0; j < n; j++) {
			if (!checked[j])
				t--;
			if (!t) {
				ans[j] = i;
				checked[j] = true;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] + 1 << ' ';
	cout << endl;

	return 0;
}
