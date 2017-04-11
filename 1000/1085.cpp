#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;


int main() {
	uint x, y, w, h;
	cin >> x >> y >> w >> h;
	
	cout << min({ w - x, x, h - y, y }) << endl;

	return 0;
}