#include <bits/stdc++.h>
#include <unordered_map>
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

#define MAX_N 4000

int cnt[2];
string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> str;
	cnt[str[0] - '0']++;
	for (int i = 1; i < str.size(); i++)
		if (str[i] != str[i - 1])
			cnt[str[i] - '0']++;

	cout << *min_element(cnt, cnt + 2) << endl;

	return 0;
}
