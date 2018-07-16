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

int tc;
int n;
int arr[MAX_N][4];
ll value[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			arr[i][0] = i * i * i;
			arr[i][1] = i * i;
			arr[i][2] = i;
			arr[i][3] = 1;

			cin >> value[i];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < n; j++) {
				int mul = arr[j][3 - i] / arr[i][3 - i];
				for (int k = 0; k < 4; k++)
					arr[j][k] -= arr[i][k] * mul;

				value[j] -= value[i] * mul;
			}
			for (int j = 0; j < 4; j++)
				arr[i][j] = 0;
			value[i] = 0;
		}

		bool ans = true;
		for (int i = 3; i < n; i++) {
			if (value[i] == 0)
				continue;

			int m = arr[i][0] / arr[3][0];
			int v = value[i] / value[3];
			if (value[i] % value[3] != 0 || v != m)
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	

	return 0;
}