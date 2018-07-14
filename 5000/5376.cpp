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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 101

int n;
string str;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;

		bool check = false;
		for (auto c : str)
			if (c == '(')
				check = true;

		if (!check) {
			int len = str.size() - 2;
			string t = str.substr(2);
			ll a = atoi(t.c_str());
			ll b = 1;
			while (len--)
				b *= 10;

			ll gc = gcd(a, b);

			cout << a / gc << '/' << b / gc << endl;
		}
		else {
			ll a = 0;
			for (int i = 2; i < str.size(); i++)
				if (str[i] >= '0' && str[i] <= '9') 
					a = a * 10 + str[i] - '0';
				
			int l, r;
			for (int i = 0; i < str.size(); i++)
				if (str[i] == '(')
					l = i;
				else if (str[i] == ')')
					r = i;

			ll t = 0;
			for (int i = 2; i < l; i++)
				t = t * 10 + str[i] - '0';
			a -= t;

			int braceLen = (r - l) - 1;
			ll b = 0;
			while (braceLen--)
				b = b * 10 + 9;
			t = l - 2;
			while (t--)
				b = b * 10;

			ll gc = gcd(a, b);
			cout << a / gc << '/' << b / gc << endl;
		}
	}
	
	return 0;
}