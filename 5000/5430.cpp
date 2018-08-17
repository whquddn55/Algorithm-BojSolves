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

#define MAX_N 100000
#define MAX_M 300

int n;
int arr[MAX_N];
string p;

int sIndex, eIndex;

bool isnum(char t) {
	return t >= '0' && t <= '9';
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		sIndex = eIndex = 0;

		cin >> p;
		cin >> n;
		string temp;
		cin >> temp;
		int t = 0;
		for (auto e : temp) {
			if (isnum(e))
				t = t * 10 + e - '0';
			else if (t) {
				arr[eIndex++] = t;
				t = 0;
			}
		}
		eIndex--;

		for (auto e : p)
			if (e == 'D')
				n--;
		if (n < 0) {
			cout << "error" << endl;
			continue;
		}

		bool toErase = false;
		for (auto e : p) {
			if (e == 'D')
				toErase ? eIndex-- : sIndex++;
			else
				toErase = !toErase;
		}

		cout << '[';
		for (int i = sIndex; i <= eIndex; i++)
			cout << arr[toErase ? eIndex - i + sIndex : i] << (i == eIndex ? "" : ",");
		cout << ']' << endl;
	}

	return 0;
}