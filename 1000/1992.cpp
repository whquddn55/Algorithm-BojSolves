#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 64

int n;
bool graph[MAXSIZE][MAXSIZE];

void get(int startY, int startX, int size) {
	bool check = true;
	for (int i = startY; i < (startY + size) && check; i++)
		for (int j = startX; j < (startX + size); j++)
			if (graph[i][j] != graph[startY][startX]) {
				check = false;
				break;
			}

	if (check)
		cout << graph[startY][startX];
	else {
		cout << '(';
		get(startY, startX, size / 2);
		get(startY, startX + size / 2, size / 2);
		get(startY + size / 2, startX, size / 2);
		get(startY + size / 2, startX + size / 2, size / 2);
		cout << ')';
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			
			graph[i][j] = c - '0';
		}

	get(0, 0, n);

	return 0;
}