#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 500001

string str;
string ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;
	cin >> str;

	if (t % 2 == 0) {
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}

	// case1 : 두 문자열 사이에 문자가 삽입 됬을 때
	bool ret = true;
	for (int i = 0; i < t / 2; i++) 
		if (str[i] != str[i + t / 2 + 1]) {
			ret = false;
			break;
		}
	if (ret)
		ans = str.substr(0, t / 2);
	
	// case2 : 뒷 문자열에 문자가 삽입 됬을 때
	int cnt = 0;
	ret = true;
	for (int i = 0; i < t / 2; i++) {
		if (str[i] != str[i + t / 2 + cnt]) {
			cnt++;
			i--;
			if (cnt >= 2) {
				ret = false;
				break;
			}
		}
	}
	if (ret) {
		string tmp = str.substr(0, t / 2);
		if (ans.size() != 0 && ans != tmp) {
			cout << "NOT UNIQUE" << endl;
			return 0;
		}
		else
			ans = tmp;
	}

	// case3 : 앞 문자열에 문자가 삽입 됬을 때
	cnt = 0;
	ret = true;
	for (int i = 0; i < t / 2; i++) {
		if (str[i + cnt] != str[i + t / 2 + 1]) {
			cnt++;
			i--;
			if (cnt >= 2) {
				ret = false;
				break;
			}
		}
	}
	if (ret) {
		string tmp = str.substr(t / 2 + 1, t / 2);
		if (ans.size() != 0 && ans != tmp) {
			cout << "NOT UNIQUE" << endl;
			return 0;
		}
		else
			ans = tmp;
	}

	if (ans.size())
		cout << ans << endl;
	else
		cout << "NOT POSSIBLE" << endl;

	return 0;
}