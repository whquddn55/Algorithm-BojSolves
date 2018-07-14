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
vector<string> ans;

bool isnum(char c) {
	return ((c - '0') >= 0) && ((c - '0') <= 9);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;

		string num("");
		for (char c : t) {
			if (isnum(c)) {
				if (num.size() == 1 && num[0] == '0')
					num.clear();
				num.push_back(c);
			}
			else {
				if (num.size())
					ans.push_back(num);
				num.clear();
			}
		}
		if (num.size())
			ans.push_back(num);
	}
	sort(ans.begin(), ans.end(), [](string& a, string& b)->bool {
		return (a.size() == b.size() ? (a < b) : (a.size() < b.size()));
	});
	for (string& e : ans)
		cout << e << endl;
	
	return 0;
}