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
#define MAX_N 50
#define MOD 1000000007

vector<vector<char>> arr[300];

void rotateLeft(char c, vector<vector<char>>& q) {
	char t1 = arr[c][0][0];
	char t2 = arr[c][0][1];
	arr[c][0][0] = arr[c][0][2];
	arr[c][0][1] = arr[c][1][2];
	arr[c][0][2] = arr[c][2][2];
	arr[c][1][2] = arr[c][2][1];
	arr[c][2][2] = arr[c][2][0];
	arr[c][2][1] = arr[c][1][0];
	arr[c][2][0] = t1;
	arr[c][1][0] = t2;

	vector<char> tq = q[0];
	for (int i = 0; i < 3; ++i)
		q[i] = q[i + 1];
	q[3] = tq;
}

void rotateRight(char c, vector<vector<char>>& q) {
	char t1 = arr[c][0][0];
	char t2 = arr[c][1][0];
	arr[c][0][0] = arr[c][2][0];
	arr[c][1][0] = arr[c][2][1];
	arr[c][2][0] = arr[c][2][2];
	arr[c][2][1] = arr[c][1][2];
	arr[c][2][2] = arr[c][0][2];
	arr[c][1][2] = arr[c][0][1];
	arr[c][0][2] = t1;
	arr[c][0][1] = t2;

	vector<char> tq = q[3];
	for (int i = 3; i > 0; --i)
		q[i] = q[i - 1];
	q[0] = tq;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;

	while(tc--) {
		int n;
		cin >> n;

		arr['U'] = {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}};
		arr['F'] = {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}};
		arr['R'] = {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}};
		arr['B'] = {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}};
		arr['L'] = {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}};
		arr['D'] = {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}};

		while(n--) {
			string command;
			cin >> command;

			vector<vector<char>> q;
			switch(command[0]) {
				case 'U':
					q.emplace_back(vector<char>({arr['B'][0][2], arr['B'][0][1], arr['B'][0][0]}));
					q.emplace_back(vector<char>({arr['R'][0][2], arr['R'][0][1], arr['R'][0][0]}));
					q.emplace_back(vector<char>({arr['F'][0][2], arr['F'][0][1], arr['F'][0][0]}));
					q.emplace_back(vector<char>({arr['L'][0][2], arr['L'][0][1], arr['L'][0][0]}));
				break;
				case 'F':
					q.emplace_back(arr['U'][2]);
					q.emplace_back(vector<char>({arr['R'][0][0], arr['R'][1][0], arr['R'][2][0]}));
					q.emplace_back(vector<char>({arr['D'][0][2], arr['D'][0][1], arr['D'][0][0]}));
					q.emplace_back(vector<char>({arr['L'][2][2], arr['L'][1][2], arr['L'][0][2]}));
				break;
				case 'R': //
					q.emplace_back(vector<char>({arr['U'][2][2], arr['U'][1][2], arr['U'][0][2]}));
					q.emplace_back(vector<char>({arr['B'][0][0], arr['B'][1][0], arr['B'][2][0]}));
					q.emplace_back(vector<char>({arr['D'][2][2], arr['D'][1][2], arr['D'][0][2]}));
					q.emplace_back(vector<char>({arr['F'][2][2], arr['F'][1][2], arr['F'][0][2]}));
				break;
				case 'B': //
					q.emplace_back(vector<char>({arr['U'][0][2], arr['U'][0][1], arr['U'][0][0]}));
					q.emplace_back(vector<char>({arr['L'][0][0], arr['L'][1][0], arr['L'][2][0]}));
					q.emplace_back(arr['D'][2]);
					q.emplace_back(vector<char>({arr['R'][2][2], arr['R'][1][2], arr['R'][0][2]}));
				break;
				case 'L':
					q.emplace_back(vector<char>({arr['U'][0][0], arr['U'][1][0], arr['U'][2][0]}));
					q.emplace_back(vector<char>({arr['F'][0][0], arr['F'][1][0], arr['F'][2][0]}));
					q.emplace_back(vector<char>({arr['D'][0][0], arr['D'][1][0], arr['D'][2][0]}));
					q.emplace_back(vector<char>({arr['B'][2][2], arr['B'][1][2], arr['B'][0][2]}));
				break;
				case 'D':
					q.emplace_back(arr['F'][2]);
					q.emplace_back(arr['R'][2]);
					q.emplace_back(arr['B'][2]);
					q.emplace_back(arr['L'][2]);
				break;
			}

			switch(command[1]) {
				case '-':
					rotateLeft(command[0], q);
					break;
				case '+':
					rotateRight(command[0], q);
					break;
			}

			switch(command[0]) {
				case 'U':
					for (int i = 0; i < 3; ++i)
						arr['B'][0][i] = q[0][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['R'][0][i] = q[1][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['F'][0][i] = q[2][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['L'][0][i] = q[3][2 - i];
				break;
				case 'F':
					arr['U'][2] = q[0];
					for (int i = 0; i < 3; ++i)
						arr['R'][i][0] = q[1][i];
					for (int i = 0; i < 3; ++i)
						arr['D'][0][i] = q[2][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['L'][i][2] = q[3][2 - i];
				break;
				case 'R':
					for (int i = 0; i < 3; ++i)
						arr['U'][i][2] = q[0][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['B'][i][0] = q[1][i];
					for (int i = 0; i < 3; ++i)
						arr['D'][i][2] = q[2][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['F'][i][2] = q[3][2 - i];
				break;
				case 'B':
					for (int i = 0; i < 3; ++i)
						arr['U'][0][i] = q[0][2 - i];
					for (int i = 0; i < 3; ++i)
						arr['L'][i][0] = q[1][i];
					arr['D'][2] = q[2];
					for (int i = 0; i < 3; ++i)
						arr['R'][i][2] = q[3][2 - i];
				break;
				case 'L':
					for (int i = 0; i < 3; ++i)
						arr['U'][i][0] = q[0][i];
					for (int i = 0; i < 3; ++i)
						arr['F'][i][0] = q[1][i];
					for (int i = 0; i < 3; ++i)
						arr['D'][i][0] = q[2][i];
					for (int i = 0; i < 3; ++i)
						arr['B'][i][2] = q[3][2 - i];
				break;
				case 'D':
					arr['F'][2] = q[0];
					arr['R'][2] = q[1];
					arr['B'][2] = q[2];
					arr['L'][2] = q[3];
				break;
			}
		}

		for (int i = 0; i < 3; ++i, cout<<endl)
			for (int j = 0; j < 3; ++j)
				cout << arr['U'][i][j];

	}
	
    return 0;
}