#include <iostream>
using namespace std;

int data[10];

int main() {
	int num = 1;
	for(int i = 0; i < 3; i++){
		int tmp;
		cin >> tmp;
		num *= tmp;
	}

	while(num != 0){
		data[num % 10]++;
		num /= 10;
	}

	for(int i = 0; i< 10; i++)
		cout << data[i] << endl;

	return 0;
}
