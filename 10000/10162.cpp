#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	int time[3] = {300, 60, 10};
	int result[3];
	for (int i = 0; i < 3; i++) {
		result[i] =  t / time[i];
		t -= (t / time[i]) * time[i];
	}
	if (t != 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i <3; i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}
