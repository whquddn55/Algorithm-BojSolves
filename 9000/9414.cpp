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

#define MAX_N 41

int n;
int arr[MAX_N];

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		ans = n = 0;
		for (int i = 0; i < MAX_N; i++) {
			cin >> arr[i];
			if (arr[i] == 0)
				break;
			n++;
		}
		sort(arr, arr + n, greater<int>());

		for (int i = 0; i < n; i++) {
			ll temp = 1;
			for (int j = 0; j <= i; j++) {
				if (temp > INF / arr[i]) {
					ans = -1; 
					break;
				}
				temp *= arr[i];
			}
			if (ans == -1)
				break;
			ans += 2 * temp;

			if (ans > 5 * 1000000) {
				ans = -1;
				break;
			}
		}

		if (ans == -1)
			cout << "Too expensive" << endl;
		else
			cout << ans << endl;
	}
	
	return 0;
}
