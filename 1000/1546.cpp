#include <iostream>
using namespace std;

#define MAXSIZE 1000

int arr[MAXSIZE];

int main() {
	int n;
	cin >> n;

	int max = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if ( max < arr[i] )
			max = arr[i];
	}

	double sum = 0.0;
	for(int i = 0; i < n; i++)
		sum += (double)arr[i]/max/n * 100;

	printf("%.2lf", sum);

	return 0;
}
