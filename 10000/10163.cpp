#include <iostream>
#include <vector>

using namespace std;
#define MAXSIZE 101

int plane[MAXSIZE][MAXSIZE];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			plane[i][j] = false;

	for (int k = 1; k <= n; k++) {
		int lbX, lbY, width, height;
		cin >> lbX >> lbY >> width >> height;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				plane[lbY + j][lbX + i] = k;
			}
		}
	}

	vector<int> result(n + 1, 0);
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			result[plane[i][j]]++;

	for (int i = 1; i <= n; i++)
		cout << result[i] << endl;


	return 0;
}
