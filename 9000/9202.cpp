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
#define MAX_N 300005
#define MOD 1000000007

struct Trie {
	bool isEnd;
	Trie *nxt[26];
	Trie() 
		:isEnd(false) {
			memset(nxt, NULL, sizeof(nxt));
		}
	void insert(string& str, int pos = 0) {
		if (pos == str.size()) {
			isEnd = true;
			return;
		}
		if (nxt[str[pos] - 'A'] == NULL)
			nxt[str[pos] - 'A'] = new Trie();
		nxt[str[pos] - 'A']->insert(str, pos + 1);
	}
	int find(string str, int pos = 0) {
		if (pos == str.size()) {
			if (isEnd)
				return 1;
			return 0;
		}
		if (nxt[str[pos] - 'A'] == NULL)
			return -1;
		return nxt[str[pos] - 'A']->find(str, pos + 1);
	}
};

int w, b;
char boggle[4][4];
Trie* root = new Trie();

set<string> in;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool visited[4][4];
string hereStr;
void dfs(int hereY, int hereX) {
	visited[hereY][hereX] = true;
	hereStr.push_back(boggle[hereY][hereX]);

	int res = root->find(hereStr);
	if (res == 1) 
		in.insert(hereStr);
	else if (res == -1) {
		visited[hereY][hereX] = false;
		hereStr.pop_back();
		return;
	}
	

	if (hereStr.size() != 8) {
		for (int i = 0; i < 8; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];
			if (nextY < 0 || nextX < 0 || nextY >= 4 || nextX >= 4)
				continue;
			if (visited[nextY][nextX])
				continue;

			dfs(nextY, nextX);
		}
	}

	visited[hereY][hereX] = false;
	hereStr.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> w;
	for (int i = 0; i < w; ++i) {
		string t;
		cin >> t;
		root->insert(t);
	}

	cin >> b;
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
			cin >> boggle[j][k];

		in.clear();

		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k) {
				memset(visited, 0, sizeof(visited));
				dfs(j, k);
			}

		int score = 0, cnt = 0;
		string ans = "";
		for (string e : in) {
			if (e.size() == 3 || e.size() == 4)
				score += 1;
			else if (e.size() == 5)
				score += 2;
			else if (e.size() == 6)
				score += 3;
			else if (e.size() == 7)
				score += 5;
			else if (e.size() == 8)
				score += 11;


			if (ans.size() < e.size())  
				ans = e;
			else
				ans = min(ans, e);

			++cnt;
		}

		cout << score << ' ' << ans << ' ' << cnt << endl;
	}

	return 0;
}
