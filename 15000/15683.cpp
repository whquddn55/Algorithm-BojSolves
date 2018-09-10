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

#define MAX_N 8

int n, m;
int arr[MAX_N][MAX_N];
vector<pii> camera;

int ans = INF;

void modify(int from, int to, int idx, bool isRow, int& value, vector<pii>& modified) {
	if (isRow) {
		if (from < to)
			for (int i = from; i < to; i++) {
				if (arr[i][idx] == 6)
					break;
				if (arr[i][idx] == 0) {
					value--;
					arr[i][idx] = -1;
					modified.emplace_back(i, idx);
				}
			}
		else
			for (int i = from; i >= to; i--) {
				if (arr[i][idx] == 6)
					break;
				if (arr[i][idx] == 0) {
					value--;
					arr[i][idx] = -1;
					modified.emplace_back(i, idx);
				}
			}
	}
	else {
		if (from < to)
			for (int i = from; i < to; i++) {
				if (arr[idx][i] == 6)
					break;
				if (arr[idx][i] == 0) {
					value--;
					arr[idx][i] = -1;
					modified.emplace_back(idx, i);
				}
			}
		else
			for (int i = from; i >= to; i--) {
				if (arr[idx][i] == 6)
					break;
				if (arr[idx][i] == 0) {
					value--;
					arr[idx][i] = -1;
					modified.emplace_back(idx, i);
				}
			}
	}
}

void recover(int& value, vector<pii>& modified) {
	value += modified.size();
	for (auto& e : modified)
		arr[e.first][e.second] = 0;
	modified.clear();
}

void get(int cameraIdx, int value) {
	if (cameraIdx == camera.size()) {
		/*if (ans > value) {
			cout << value << endl;
			for (int i = 0; i < n; i++, cout << endl)
				for (int j = 0; j < m; j++)
					cout << (arr[i][j] == -1 ? 9 : arr[i][j])<< ' ';
		}*/
		ans = min(ans, value);
		return;
	}

	pii pos = camera[cameraIdx];

	vector<pii> modified;
	switch (arr[pos.first][pos.second]) {
	case 1: {
		//1
		modify(pos.first, n, pos.second, true, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//2
		modify(pos.first, 0, pos.second, true, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//3
		modify(pos.second, m, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//4
		modify(pos.second, 0, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);

		break;
	}
	case 2: {
		//1
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.first, 0, pos.second, true, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//2
		modify(pos.second, m, pos.first, false, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);

		break;
	}
	case 3: {
		//1
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.second, m, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//2
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//3
		modify(pos.first, 0, pos.second, true, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//4
		modify(pos.first, 0, pos.second, true, value, modified);
		modify(pos.second, m, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);

		break;
	}
	case 4: {
		//1
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.first, 0, pos.second, true, value, modified);
		modify(pos.second, m, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//2
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.first, 0, pos.second, true, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//3
		modify(pos.first, 0, pos.second, true, value, modified);
		modify(pos.second, m, pos.first, false, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);
		//4
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		modify(pos.second, m, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);

		break;
	}
	case 5: {
		modify(pos.first, n, pos.second, true, value, modified);
		modify(pos.first, 0, pos.second, true, value, modified);
		modify(pos.second, 0, pos.first, false, value, modified);
		modify(pos.second, m, pos.first, false, value, modified);
		get(cameraIdx + 1, value);
		recover(value, modified);

		break;
	}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)
				camera.emplace_back(i, j);
			if (arr[i][j] == 0)
				cnt++;
		}

	get(0, cnt);
	cout << ans << endl;

	return 0;
}