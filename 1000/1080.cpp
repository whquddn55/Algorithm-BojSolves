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

#define MAX_N 50

int n, m;
bool arr1[MAX_N][MAX_N];
bool arr2[MAX_N][MAX_N];

int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			arr1[i][j] = (t == '1' ? true : false);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			arr2[i][j] = (t == '1' ? true : false);
		}

	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
			if (arr1[i][j] != arr2[i][j]) {
				ans++;
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						arr1[i + k][j + l] = !arr1[i + k][j + l];
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr1[i][j] != arr2[i][j])
				ans = -1;
	cout << ans << endl;
 	
	return 0;
}
