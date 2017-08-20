#include <iostream>
using namespace std;

#define MAXSIZE 1000

int main() {
	int t;
	cin >> t;

	int score[MAXSIZE];
	while(t--){
		int n;
		cin >> n;

		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> score[i];
			sum += score[i];
		}

		double avg = (double)sum / n;
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if ((double)score[i] > avg)
				cnt++;

		printf("%.3lf%%\n", (double)cnt / n * 100);
	}


	return 0;
}
