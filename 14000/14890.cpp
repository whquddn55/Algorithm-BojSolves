#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (LLONG_MAX / 2)

#define MAX_N 100

int n, l;
int arr[MAX_N][MAX_N];

int ans = 0;

void get() {
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int j = 0; j < n; j++)
			if (arr[i][j] != arr[i][0])
				check = false;

		if (check) {
			ans++;
			continue;
		}

		int here = 0;
		int len = 0;
		check = true;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == arr[i][here])
				len++;
			else {
				if (arr[i][j] > arr[i][here]) {
					if (arr[i][j] > arr[i][here] + 1)
						check = false;
					if (len < l)
						check = false;

					len = 1;
					here = j;
				}
				else {
					if (arr[i][j] < arr[i][here] - 1)
						check = false;

					if (j + l > n) {
						check = false;
						break;
					}

					for (int k = j; k < j + l; k++)
						if (arr[i][k] != arr[i][j])
							check = false;

					len = 0;
					here = j;
					j = j + l - 1;
				}
			}

		}

		if (check)
			ans++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	get();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(arr[i][j], arr[j][i]);
	get();
	
	cout << ans << endl;

	return 0;
}