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

#define INF (INT_MAX / 2)

#define MAX_N 105
#define MOD 1000000007

int w, h;
int posY, posX;
int t;

int status = 0;
int dy[4] = { 1, 1, -1, -1 };
int dx[4] = { 1, -1, -1, 1 };

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> w >> h;
	cin >> posX >> posY;

	cin >> t;

	while (t) {
		switch (status) {
		case 0: { // 우상
			int distY = h - posY;
			int distX = w - posX;
			if (distY > distX) {
				status = 1;
				if (t < distX)
					distX = t;

				t -= distX;
				posX += distX;
				posY += distX;
			}
			else {
				status = 3;
				if (t < distY)
					distY = t;

				t -= distY;
				posX += distY;
				posY += distY;
			}
			break;
		}
		case 1: { // 좌상
			int distY = h - posY;
			int distX = posX;
			if (distY > distX) {
				status = 0;
				if (t < distX)
					distX = t;

				t -= distX;
				posX -= distX;
				posY += distX;
			}
			else {
				status = 2;
				if (t < distY)
					distY = t;

				t -= distY;
				posX -= distY;
				posY += distY;
			}
			break;
		}
		case 2: { // 좌하
			int distY = posY;
			int distX = posX;
			if (distY > distX) {
				status = 3;
				if (t < distX)
					distX = t;

				t -= distX;
				posX -= distX;
				posY -= distX;
			}
			else {
				status = 1;
				if (t < distY)
					distY = t;

				t -= distY;
				posX -= distY;
				posY -= distY;
			}
			break;
		}
		case 3: { // 우하
			int distY = posY;
			int distX = w - posX;
			if (distY > distX) {
				status = 2;
				if (t < distX)
					distX = t;

				t -= distX;
				posX += distX;
				posY -= distX;
			}
			else {
				status = 0;
				if (t < distY)
					distY = t;

				t -= distY;
				posX += distY;
				posY -= distY;
			}
			break;
		}
		}

	}
	cout << pii(posX, posY) << endl;
	

	return 0;
}