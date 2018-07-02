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

#define MAX_N 100

int n, m;
int a, b;
int num;
string arr[MAX_N];
int underbar[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (islower(arr[i][0]))
			a++;
		else
			b++;
		m -= arr[i].size();
	}

	for (int i = 1; i < n; i++)
		underbar[i] = m / (n - 1);
	m %= (n - 1);

	for (int i = 1; i < n && m; i++)
		if (islower(arr[i][0])) {
			underbar[i]++;
			m--;
		}

	for (int i = n - 1; i >= 1 && m; i--)
		if (isupper(arr[i][0])) {
			underbar[i]++;
			m--;
		}

	for (int i = 0; i < n; i++) {
		while (underbar[i]--)
			cout << '_';
		cout << arr[i];
	}

	return 0;
}
