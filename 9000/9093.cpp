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

#define MAX_N 100

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--) {
		getline(cin, str);
		int index = 0;
		while (true) {
			int next = str.find(' ', index);
			if (next > str.size())
				next = str.size();
			for (int i = next - 1; i >= index; i--)
				cout << str[i];
			index = next + 1;
			if (next == str.size())
				break;
			cout << ' ';
		}
		cout << endl;
	}

	return 0;
}