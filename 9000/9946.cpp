#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (LLONG_MAX / 2)

#define MAX_N 5

int cnt[26];
string str1, str2;

bool ans;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc = 1;
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		ans = true;
		cin >> str1 >> str2;
		if (str1 == "END" && str2 == "END")
			break;

		for (auto e : str1)
			cnt[e - 'a']++;
		for (auto e : str2)
			cnt[e - 'a']--;

		for (int i = 0; i < 26; i++)
			if (cnt[i])
				ans = false;
		cout << "Case " << tc++ << ": ";
		cout << (ans ? "same" : "different") << endl;
	}
	
	return 0;
}