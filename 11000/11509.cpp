#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 1000000;

int h[MAXSIZE];
int arrow[MAXSIZE] = { 0, };

int main() {
	int n;
	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cin >> h[i];

	for (int i = 0; i < n; i++) {
		if (arrow[h[i]] == 0) {
			cnt++;
			arrow[h[i] - 1]++;
		}
		else {
			arrow[h[i]]--;
			arrow[h[i] - 1]++;
		}
	}

	cout << cnt << endl;

	return 0;
}