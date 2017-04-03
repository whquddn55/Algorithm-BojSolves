#include <iostream>
using namespace std;

int getNew(int n);

int main() {
	int n;
	cin >> n;
	int result = n,count = 0;
	while (true) {
		result = getNew(result);
		count++;
		if (result == n)
			break;
	}

	cout << count << '\n';

	return 0;
}

int getNew(int n) {
	int returnValue;
	if (n < 10)
		returnValue = n * 11;
	else
		returnValue = (n % 10)*10 + ((n % 10) + (n / 10)) % 10;
	
	return returnValue;
}