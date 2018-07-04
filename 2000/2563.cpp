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

#define MAX_N 201

int n;
int arr[MAX_N][MAX_N];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i < a + 10; i++)
			for (int j = b; j < b + 10; j++)
				arr[i][j] = 1;
	}
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			ans += arr[i][j];
	cout << ans << endl;

	
	return 0;
}