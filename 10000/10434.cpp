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

#define MAX_N 605

int n;
bool isNotPrime[10001];
bool isAppeared[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i <= 100; i++)
		if (!isNotPrime[i])
			for (int j = i * 2; j <= 10000; j += i)
				isNotPrime[j] = true;

	int tc;
	cin >> tc;
	while (tc--) {
		memset(isAppeared, false, sizeof(isAppeared));

		int t;
		cin >> t >> n;
		cout << pii(t, n) << ' ';

		if (isNotPrime[n]) {
			cout << "NO" << endl;
			continue;
		}

		int temp = n;
		isAppeared[n] = true;
		while (temp != 1) {
			int value[5] = { 0, };
			for (int i = 0; i < 5; i++) {
				value[i] = temp % 10;
				temp /= 10;
			}

			temp = 0;
			for (int i = 0; i < 5; i++)
				temp += value[i] * value[i];

			if (isAppeared[temp])
				break;
			isAppeared[temp] = true;
		}
		if (temp == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}
