#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 300;
int arr[MAXSIZE][MAXSIZE];
int main() {
	int sizeI, sizeJ;
	cin >> sizeI >> sizeJ;

	for (int i = 0; i < sizeI; i++)
		for (int j = 0; j < sizeJ; j++)
			cin >> arr[i][j];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		int result = 0;
		for (int j = startX - 1; j < endX; j++)
			for (int k = startY - 1; k < endY; k++)
				result += arr[j][k];

		cout << result << endl;
	}


	return 0;
}