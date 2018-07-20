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

string str;
int cnt[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> str;
	bool isStart = true;
	for (auto e : str) {
		if (isStart) {
			isStart = false;
			if (e == 'A' || e == 'D' || e == 'E')
				cnt[0]++;
			else if (e == 'C' || e == 'F' || e == 'G')
				cnt[1]++;
		}
		if (e == '|')
			isStart = true;
	}

	if (cnt[0] == cnt[1]) {
		char e = str.back();
		if (e == 'A' || e == 'D' || e == 'E')
			cnt[0]++;
		else if (e == 'C' || e == 'F' || e == 'G')
			cnt[1]++;
	}

	if (cnt[0] < cnt[1])
		cout << "C-major" << endl;
	else
		cout << "A-minor" << endl;

	return 0;
}
