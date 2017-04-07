#include <iostream>
using namespace std;

unsigned int GCD(unsigned int num1,unsigned int num2);
unsigned int LCM(unsigned int num1,unsigned int num2);

int main() {
	unsigned int num1, num2;
	cin >> num1 >> num2;

	cout << GCD(num1, num2) << endl;
	cout << LCM(num1, num2) << endl;


	return 0;
}

unsigned int GCD(unsigned int num1, unsigned int num2) {
	unsigned int q = num1/num2, r = num1%num2;

	while (true) {
		if (r == 0)
			break;

		num1 = num2;
		num2 = r;
		q = num1 / num2;
		r = num1 % num2;
	}

	return num2;
}
unsigned int LCM(unsigned int num1, unsigned int num2) {
	unsigned int gcd = GCD(num1, num2);

	return gcd * (num1 / gcd) * (num2 / gcd);
}