#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

int main() {
	uint queue[10001], front = 0, back = 0;
	uint num;
	cin >> num;
	for (uint i = 0; i < num; i++) {
		string input;
		cin >> input;

		if (!input.compare("push")) {
			uint value;
			cin >> value;
			queue[back] = value;
			back++;
		}
		else if (!input.compare("pop")) {
			if ((back - front) == 0)
				cout << -1 << endl;
			else {
				cout << queue[front] << endl;
				front++;
			}
		}
		else if (!input.compare("size")) {
			cout << (back - front) << endl;
		}
		else if (!input.compare("empty")) {
			if ((back - front) == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (!input.compare("front")) {
			if ((back - front) == 0)
				cout << -1 << endl;
			else
				cout << queue[front] << endl;
		}
		else if (!input.compare("back")) {
			if ((back - front) == 0)
				cout << -1 << endl;
			else
				cout << queue[back - 1] << endl;
		}
	}
	return 0;
}