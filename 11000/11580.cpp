#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 2001

bool graph[MAXSIZE][MAXSIZE];

int main() {
	int n;
	cin >> n;

	string command;
	cin >> command;

	int hereY = n, hereX = n;
	graph[hereY][hereX] = true;
	for (char c : command) {
		if (c == 'E' && hereX >= 0) 
			hereX -= 1;
		if (c == 'W' && hereX < n * 2 + 1)
			hereX += 1;
		if (c == 'S' && hereY < n * 2 + 1)
			hereY += 1;
		if (c == 'N' && hereX >= 0)
			hereY -= 1;

		graph[hereY][hereX] = true;
	}

	int result = 0;
	for (int i = 0; i < n * 2 + 1; i++)
		for (int j = 0; j < n * 2 + 1; j++)
			if (graph[i][j])
				result++;
	cout << result << endl;
}