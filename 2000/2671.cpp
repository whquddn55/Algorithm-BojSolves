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

#define INF (INT_MAX / 2)

#define MAX_N 50

int status = 0;
string str;
string ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> str;
	for (auto& e : str)
		e -= '0';

	for (auto e : str) {
		if (status == -1)
			break;
		switch (status) {
		case 0:
			if (e)
				status = 2;
			else
				status = 1;
			break;
		case 1:
			if (e)
				status = 0;
			else
				status = -1;
			break;
		case 2:
			if (e)
				status = -1;
			else
				status = 3;
			break;
		case 3:
			if (e)
				status = -1;
			else
				status = 4;
			break;
		case 4:
			if (e)
				status = 5;
			break;
		case 5:
			if (e)
				status = 6;
			else
				status = 1;
			break;
		case 6:
			if (!e)
				status = 7;
			break;
		case 7:
			if (e)
				status = 0;
			else
				status = 4;
			break;
		}
	}
	if (status == 0 || status == 5 || status == 6)
		ans = "SUBMARINE";
	else
		ans = "NOISE";
	cout << ans << endl;

	return 0;
}