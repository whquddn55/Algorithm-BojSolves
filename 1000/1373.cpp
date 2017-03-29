#include <iostream>
using namespace std;
int main() {
	char* oct = new char[1000001];
	int i = 0;
	while (true) { 
		oct[i] = cin.get();
		if (oct[i] == '\n')
			break;
		i++; 
	}

	int j, num[3] = {oct[0] - '0',oct[1] - '0',oct[2] - '0' };
	if (i % 3 == 0) {
		cout << ((oct[0] - '0') * 4 + (oct[1] - '0') * 2 + (oct[2] - '0'));
		j = 3;
	}
	else if (i % 3 == 1) {
		cout << (oct[0] - '0');
		j = 1;
	}
	else {
		cout << ((oct[0] - '0') * 2 + (oct[1] - '0'));
		j = 2;
	}
	for (; j < i; j += 3) 
		cout << ((oct[j] - '0') * 4 + (oct[j+1] - '0') * 2 + (oct[j+2] - '0'));

	cout << endl;
	return 0;

}