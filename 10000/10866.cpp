#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

void shiftDeque(uint* deque, uint front, uint back);

int main() {
	uint deque[10001], front = 0, back = 0;
	uint num;
	cin >> num;
	for (uint i = 0; i < num; i++) {
		string input;
		cin >> input;

		if (!input.compare("push_front")) {
			uint value;
			cin >> value;
			shiftDeque(deque, front, back);
			back++;
			deque[front] = value;
		}
		else if (!input.compare("push_back")) {
			uint value;
			cin >> value;
			deque[back] = value;
			back++;
		}
		else if (!input.compare("pop_front")) {
			if (front == back)
				cout << -1 << endl;
			else {
				cout << deque[front] << endl;
				front++;
			}
		}
		else if (!input.compare("pop_back")) {
			if (front == back)
				cout << -1 << endl;
			else {
				cout << deque[back - 1] << endl;
				back--;
			}
		}
		else if (!input.compare("size")) {
			cout << back - front << endl;
		}
		else if (!input.compare("empty")) {
			if (front == back)
				cout << 1 << endl;
			else
				cout << 0 << endl;
				
		}
		else if (!input.compare("front")) {
			if (front == back)
				cout << -1 << endl;
			else
				cout << deque[front] << endl;
		}
		else if (!input.compare("back")) {
			if (front == back)
				cout << -1 << endl;
			else
				cout << deque[back - 1] << endl;
		}
	}
	return 0;
}

void shiftDeque(uint* deque, uint front, uint back) {
	//uint temp = deque[front + 1];
	uint temp1 = deque[front + 1];
	uint temp2 = deque[front];
	for (uint i = front; i < back; i++) {
		if (i == front)
			deque[i + 1] = deque[i];
		else {
			temp2 = temp1;
			temp1 = deque[i + 1];
			deque[i + 1] = temp2;
		}
	}
}
