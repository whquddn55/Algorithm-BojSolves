#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << (a > b ? (b > c ? b : (a > c ? c : a)) : (a > c ? a : (b > c ? c : b))) << endl;
	return 0;
}