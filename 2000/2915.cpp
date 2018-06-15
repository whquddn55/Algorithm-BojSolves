#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator<<(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 30001

int start = -1;
string str;


int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'I' || str[i] == 'V') {
			start = i;
			break;
		}
	}
	if (start == -1)
		start = str.size();

	// VI -> IV
	for (int i = start; i < str.size(); i++) {
		if (str[i] == 'V') {
			int cnt = 0;
			for (int j = i + 1; j < str.size(); j++)
				if (str[j] == 'I')
					cnt++;
			if (cnt == 1)
				swap(str[i], str[i + 1]);
		}
	}

	// LX -> XL
	if (str.substr(0, start) == "LX" || (str.substr(0, start) == "LXX" && start != str.size() && str.substr(start) == "I"))
		swap(str[0], str[1]);

	// XI -> IX
	if (start != str.size()) {
		if (start == str.size() - 1 && start != 0 && str[start] == 'I' && str[start - 1] == 'X')
			swap(str[start - 1], str[start]);
	}

	cout << str << endl;
	

	return 0;
}