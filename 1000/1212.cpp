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

#define MAX_N 20000

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> str;
	bool isStart = true;
	for (auto e : str) {
		e -= '0';
		if (isStart)
			switch (e) {
			case 0:
				cout << "0";
				break;
			case 1:
				cout << "1";
				break;
			case 2:
				cout << "10";
				break;
			case 3:
				cout << "11";
				break;
			case 4:
				cout << "100";
				break;
			case 5:
				cout << "101";
				break;
			case 6:
				cout << "110";
				break;
			case 7:
				cout << "111";
				break;
			}
		else
			switch (e) {
			case 0:
				cout << "000";
				break;
			case 1:
				cout << "001";
				break;
			case 2:
				cout << "010";
				break;
			case 3:
				cout << "011";
				break;
			case 4:
				cout << "100";
				break;
			case 5:
				cout << "101";
				break;
			case 6:
				cout << "110";
				break;
			case 7:
				cout << "111";
				break;
			}
		isStart = false;
	}
	
	return 0;
}
