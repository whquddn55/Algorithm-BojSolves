#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 51

ll d, x, y;
string s;
ll maxLen = 1;
ll posX, posY;
string ans;

void getPos(ll hereY, ll hereX, ll idx, ll len) {
	if (idx == s.size()) {
		posX = hereX;
		posY = hereY;
		return;
	}

	switch (s[idx]) {
	case '1':
		getPos(hereY, hereX + len / 2, idx + 1, len / 2);
		break;
	case '2':
		getPos(hereY, hereX, idx + 1, len / 2);
		break;
	case '3':
		getPos(hereY + len / 2, hereX, idx + 1, len / 2);
		break;
	case '4':
		getPos(hereY + len / 2, hereX + len / 2, idx + 1, len / 2);
		break;
	}
}

void getPos2(ll len) {
	if (len == 0)
		return;

	if (posY < len && posX < len) 
		ans.push_back('2');
	else if (posY < len && posX >= len) {
		ans.push_back('1');
		posX -= len;
	}
	else if (posY >= len && posX < len) {
		ans.push_back('3');
		posY -= len;
	}
	else {
		ans.push_back('4');
		posY -= len;
		posX -= len;
	}
	getPos2(len / 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> d >> s;
	cin >> x >> y;
	for (int i = 0; i < d; i++)
		maxLen *= 2;

	getPos(0, 0, 0, maxLen);
	posY += -y;
	posX += x;
	if (posY >= maxLen || posY < 0 || posX >= maxLen || posX < 0) 
		cout << -1 << endl;
	else {
		getPos2(maxLen / 2);
		cout << ans << endl;
	}

	return 0;
}
