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


#define INF (INT_MAX / 2)
#define MOD 1000000007

#define MAX_N 11

int n, m;
char arr[MAX_N][MAX_N];
pii red, blue;
int result = INF;

int moveRed(int dy, int dx);

int moveBlue(int dy, int dx) { // 0: 더 이상 못 움직인다(벽 or red). 1: 움직일 수 있어서 움직였다. -1: hole에 들어갔다.
    bool moved = false;
    const pii orgBlue = blue;
    while(true) {
        blue.first += dy;
        blue.second += dx;

        if (arr[blue.first][blue.second] == '#') {
            blue.first -= dy;
            blue.second -= dx;
            break;
        }
        else if (arr[blue.first][blue.second] == 'R') {
            blue.first -= dy;
            blue.second -= dx;
            int redMoveResult = moveRed(dy, dx);
            if (redMoveResult == 0)
                break;
            if (redMoveResult == -1) {
                blue = orgBlue;
                return -1;
            }
        }
        else if (arr[blue.first][blue.second] == 'O') {
            blue = orgBlue;
            return -1;
        }
        
        moved = true;
    }
    arr[orgBlue.first][orgBlue.second] = '.';
    arr[blue.first][blue.second] = 'B';
    return moved;
}

int moveRed(int dy, int dx) { // 0: 더 이상 못 움직인다(벽 or red). 1: 움직일 수 있어서 움직였다. -1: hole에 들어갔다.
    bool moved = false;
    const pii orgRed = red;
    while(true) {
        red.first += dy;
        red.second += dx;

        if (arr[red.first][red.second] == '#') {
            red.first -= dy;
            red.second -= dx;
            break;
        }
        else if (arr[red.first][red.second] == 'B') {
            red.first -= dy;
            red.second -= dx;
            int blueMoveResult = moveBlue(dy, dx);
            if (blueMoveResult == 0)
                break;
            if (blueMoveResult == -1) {
                red = orgRed;
                return -1;
            }
        }
        else if (arr[red.first][red.second] == 'O') {
            red = orgRed;
            return -1;
        }

        moved = true;
    }
    arr[orgRed.first][orgRed.second] = '.';
    arr[red.first][red.second] = 'R';
    return moved;
}

int tilt(int dy, int dx) {
    int blueMoveResult = moveBlue(dy, dx);
    int redMoveResult = moveRed(dy, dx);

    if (redMoveResult == -1 && blueMoveResult != -1)
        return 1;
    else if (redMoveResult == -1 || blueMoveResult == -1)
        return -1;
    return 0;
}

void get(int use) {
	if (use == 11)
		return;

    const pii originalRed = red;
	const pii originalBlue = blue;

    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {-1, 0, 1, 0};
    for (int i = 0; i < 4; ++i) {
        int check = tilt(dy[i], dx[i]);
        if (check != 0) {
            if (check == 1) 
                result = min(result, use);
            
            arr[red.first][red.second] = '.';
            arr[originalRed.first][originalRed.second] = 'R';
            red = originalRed;
            arr[blue.first][blue.second] = '.';
            arr[originalBlue.first][originalBlue.second] = 'B';
            blue = originalBlue;
            continue;
        }
        get(use + 1);

        arr[red.first][red.second] = '.';
        arr[originalRed.first][originalRed.second] = 'R';
        red = originalRed;
        arr[blue.first][blue.second] = '.';
        arr[originalBlue.first][originalBlue.second] = 'B';
        blue = originalBlue;
    }
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				red = { i, j };
			else if (arr[i][j] == 'B')
				blue = { i, j };
		}

	get(1);
	cout << (result == INF ? -1 : result) << endl;

	return 0;
}