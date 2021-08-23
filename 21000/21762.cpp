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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 200005
#define MOD 1000003

string a, b, w;
int psumA[MAX_N][26];
int psumB[MAX_N][26];
int preA[MAX_N];
int sufA[MAX_N];
int preB[MAX_N];
int sufB[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--) {
		memset(psumA[0], 0, sizeof(psumA[0]));
		memset(psumB[0], 0, sizeof(psumB[0]));
		cin >> a >> b >> w;

		psumA[0][a[0] - 'a'] = 1;
		int widx = 0;
		int wridx = w.size() - 1;
		if (a[0] == w[0]) {
			preA[widx] = 0;
			++widx;
		}
		if (a.back() == w.back()) {
			sufA[wridx] = a.size() - 1;
			--wridx;
		}
		for (int i = 1; i < a.size(); ++i) {
			for (int j = 0; j < 26; ++j)
				psumA[i][j] = psumA[i - 1][j] ;
			psumA[i][a[i] - 'a']++;

			if (widx != w.size()) {
				if (a[i] == w[widx]) {
					preA[widx] = i;
					++widx;
				}
			}

			if (wridx != -1) {
				if (a[a.size() - 1 - i] == w[wridx]) {
					sufA[wridx] = a.size() - 1 - i;
					--wridx;
				}
			}
		}

		psumB[0][b[0] - 'a'] = 1;
		widx = 0;
		wridx = w.size() - 1;
		if (b[0] == w[0]) {
			preB[widx] = 0;
			++widx;
		}
		if (b.back() == w.back()) {
			sufB[wridx] = b.size() - 1;
			--wridx;
		}
		for (int i = 1; i < b.size(); ++i) {
			for (int j = 0; j < 26; ++j)
				psumB[i][j] = psumB[i - 1][j] ;
			psumB[i][b[i] - 'a']++;

			if (widx != w.size()) {
				if (b[i] == w[widx]) {
					preB[widx] = i;
					++widx;
				}
			}

			if (wridx != -1) {
				if (b[b.size() - 1 - i] == w[wridx]) {
					sufB[wridx] = b.size() - 1 - i;
					--wridx;
				}
			}
		}

		bool ans = false;
		for (int i = 0; i <= w.size(); ++i) {
			if (ans)
				break;
			for (int j = 0; j < 26; ++j) {
				int fa = (i - 1 < 0 ? 0 : psumA[preA[i - 1]][j]);
				int ta = (i == w.size() ? psumA[a.size() - 1][j] : psumA[sufA[i] - 1][j]);
				int fb = (i - 1 < 0 ? 0 : psumB[preB[i - 1]][j]);
				int tb = (i == w.size() ? psumB[b.size() - 1][j] : psumB[sufB[i] - 1][j]);
				if (fa < ta && fb < tb) {
					ans = true;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
