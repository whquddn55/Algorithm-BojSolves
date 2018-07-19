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

#define MAX_N 10001

string str;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> str;
		for (auto& e : str)
			e -= '0';

		int status = 0;

		bool ans = true;
		for (auto e : str) {
			switch (status) {
			case 0: {
				if (e == 0)
					status = 6;
				else
					status = 1;
				break;
			}
			case 1: {
				if (e == 0)
					status = 2;
				else
					ans = false;
				break;
			}
			case 2: {
				if (e == 0)
					status = 3;
				else
					ans = false;
				break;
			}
			case 3: {
				if (e == 0)
					status = 3;
				else
					status = 4;
				break;
			}
			case 4: {
				if (e == 0)
					status = 6;
				else
					status = 5;
				break;
			}
			case 5: {
				if (e == 0)
					status = 7;
				else
					status = 5;
				break;
			}
			case 6: {
				if (e == 0)
					ans = false;
				else
					status = 0;
				break;
			}
			case 7: {
				if (e == 0)
					status = 3;
				else
					status = 0;
				break;
			}
			}
		}

		if (status != 0 && status != 4 && status != 5)
			ans = false;

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}