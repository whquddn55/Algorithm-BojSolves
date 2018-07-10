#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)

#define MAX_N 10001

string str;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	string t;
	while (cin >> t) {
		str.append(t);
		str.push_back(' ');
	}
	str = str.substr(0, str.size() - 6);

	string temp = "";
	string ans = "";
	for (auto e : str) {
		if (isalpha(e) || e == '-')
			temp.push_back(e);
		else {
			if (ans.size() < temp.size()) 
				ans = temp;
			temp.clear();
		}
	}
	if (ans.size() < temp.size())
		ans = temp;
	for (auto e : ans)
		cout << (char)tolower(e);
	cout << endl;
	
	return 0;
}