#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;

	vector < vector<char> > paper(r);
	for (int i = 0; i < r; i++) {
		paper[i].resize(c);
		for (int j = 0; j < c; j++)
			cin >> paper[i][j];
	}

	for (int i = 0; i < r; i++) {
		for (int k1 = 0; k1 < zr; k1++) {
			for (int j = 0; j < c; j++)
				for (int k2 = 0; k2 < zc; k2++)
					cout << paper[i][j];
			cout << endl;
		}
	}
}