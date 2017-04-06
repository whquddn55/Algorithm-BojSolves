#include <iostream>
using namespace std;

unsigned int getLastNum(unsigned int a, unsigned int b); 

int main(){
	unsigned int t;
	cin >> t;

	unsigned int a,b;
	for(unsigned int i = 0; i < t; i ++){
		cin >> a >> b;
		cout << getLastNum(a%10,b) << '\n';
	}

	return 0;
}

unsigned int getLastNum(unsigned int a, unsigned int b){
	int sample[10][4] = {{10,10,10,10},{1,1,1,1},{6,2,4,8},
						{1,3,9,7},{6,4,6,4},{5,5,5,5},
						{6,6,6,6},{1,7,9,3},{6,8,4,2},
						{1,9,1,9}};
	const unsigned int result = sample[a][b%4];

	return result;
}