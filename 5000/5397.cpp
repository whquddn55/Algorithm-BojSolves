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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

list<char> arr;
list<char>::iterator iter;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		arr.clear();
		iter = arr.begin();

		string str;
		cin >> str;
		for (auto t : str) {
			if (t == '<') {
				if (iter != arr.begin())
					iter--;
			}
			else if (t == '>') {
				if (iter != arr.end())
					iter++;
			}
			else if (t == '-') {
				if (iter != arr.begin()) {
					iter--;
					iter = arr.erase(iter);
				}
			}
			else {
				iter = arr.insert(iter, t);
				iter++;
			}

		}
		for (auto e : arr)
			cout << e;
		cout << endl;
	}
	
	return 0;
}
