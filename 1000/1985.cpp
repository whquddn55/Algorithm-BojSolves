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

#define MAX_N 100000

string str1, str2;
map<int, int> m1, m2;

bool comp() {
	for (auto e : m1)
		if (e.second != 0 && m2[e.first] == 0)
			return false;
	for (auto e : m2)
		if (e.second != 0 && m1[e.first] == 0)
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (cin >> str1 >> str2) {
		m1.clear();
		m2.clear();
		for (auto e : str1)
			m1[e]++;
		for (auto e : str2)
			m2[e]++;


		if (comp()) 
			cout << "friends" << endl;
		else {
			bool printed = false;
			for (int i = 0; i < str1.size() - 1 && !printed; i++) {
				// i에 ++, i + 1에 --
				if (str1[i] != '9' && str1[i + 1] != '0' && !printed) {
					m1[str1[i]]--;
					m1[str1[i + 1]]--;
					m1[str1[i] + 1]++;
					m1[str1[i + 1] - 1]++;
					if (comp()) {
						cout << "almost friends" << endl;
						printed = true;
					}
					m1[str1[i] + 1]--;
					m1[str1[i + 1] - 1]--;
					m1[str1[i]]++;
					m1[str1[i + 1]]++;
				}

				if (i == 0 && str1[i] == '1')
					continue;

				// i에 --, i + 1에 ++
				if (str1[i] != '0' && str1[i + 1] != '9' && !printed) {
					m1[str1[i]]--;
					m1[str1[i + 1]]--;
					m1[str1[i] - 1]++;
					m1[str1[i + 1] + 1]++;
					if (comp()) {
						cout << "almost friends" << endl;
						printed = true;
					}
					m1[str1[i] - 1]--;
					m1[str1[i + 1] + 1]--;
					m1[str1[i]]++;
					m1[str1[i + 1]]++;
				}
			}

			for (int i = 0; i < str2.size() - 1 && !printed; i++) {
				// i에 ++, i + 1에 --
				if (str2[i] != '9' && str2[i + 1] != '0' && !printed) {
					m2[str2[i]]--;
					m2[str2[i + 1]]--;
					m2[str2[i] + 1]++;
					m2[str2[i + 1] - 1]++;
					if (comp()) {
						cout << "almost friends" << endl;
						printed = true;
					}
					m2[str2[i] + 1]--;
					m2[str2[i + 1] - 1]--;
					m2[str2[i]]++;
					m2[str2[i + 1]]++;
				}

				if (i == 0 && str2[i] == '1')
					continue;
					
				// i에 --, i + 1에 ++
				if (str2[i] != '0' && str2[i + 1] != '9' && !printed) {
					m2[str2[i]]--;
					m2[str2[i + 1]]--;
					m2[str2[i] - 1]++;
					m2[str2[i + 1] + 1]++;
					if (comp()) {
						cout << "almost friends" << endl;
						printed = true;
					}
					m2[str2[i] - 1]--;
					m2[str2[i + 1] + 1]--;
					m2[str2[i]]++;
					m2[str2[i + 1]]++;
				}
			}

			if (!printed)
				cout << "nothing" << endl;
		}
	}

	return 0;
}
