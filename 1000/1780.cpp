#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 2187

int n;
int paper[MAXSIZE][MAXSIZE];
int result[3];

void get(int startY, int startX, int size) {
	if (size == 1) {
		result[paper[startY][startX]]++;
		return;
	}

	bool flag = true;
	for (int i = startY; i < (startY + size) && flag; i++)
		for (int j = startX; j < (startX + size); j++)
			if (paper[i][j] != paper[startY][startX]) {
				flag = false;
				break;
			}

	if (flag)
		result[paper[startY][startX]]++;
	else {
		int dy[] = { 0, 0, 0, size / 3, size / 3, size / 3, (size * 2) / 3, (size * 2) / 3 , (size * 2) / 3 };
		int dx[] = { 0, size / 3, (size * 2) / 3 , 0, size / 3, (size * 2) / 3 , 0, size / 3, (size * 2) / 3 };
		for (int i = 0; i < 9; i++) 
			get(startY + dy[i], startX + dx[i], size / 3);
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			paper[i][j] = temp + 1;
		}

	get(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << result[i] << endl;

	return 0;
}