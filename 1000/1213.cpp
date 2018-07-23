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

#define MAX_N 500

map<char, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		m[str[i]]++;

	int oddCnt = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second % 2)
			oddCnt++;
	}
	if (oddCnt >= 2 || (oddCnt == 1 && str.size() % 2 == 0)) {
		cout << "I\'m Sorry Hansoo" << endl;
		return 0;
	}

	map<char, int>::iterator oddIt = m.end();
	for (auto i = m.begin(); i != m.end(); ++i)
		if (i->second % 2) {
			oddIt = i;
			oddIt->second--;
		}

	int cnt = 0;
	auto it = m.begin();
	while (cnt < str.size() / 2) {
		int pCnt = it->second / 2;
		for (int i = 0; i < pCnt && cnt < str.size() / 2; i++) {
			cout << it->first;
			cnt++;
		}
		it->second /= 2;
		++it;
		
	}

	if (oddIt != m.end()) 
		cout << oddIt->first;

	it = m.end();
	--it;
	cnt = 0;
	while (cnt < str.size() / 2) {
		int pCnt = it->second;
		for (int i = 0; i < pCnt && cnt < str.size() / 2; i++) {
			cout << it->first;
			cnt++;
		}
		--it;
	}
	
	
	return 0;
}
