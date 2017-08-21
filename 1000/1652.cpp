#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 100

int main() {
	int n;
	cin >> n;

	bool room[MAXSIZE][MAXSIZE];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
		char ch;
		cin >> ch;

		if(ch == '.')
			room[i][j] = true;
		else
			room[i][j] = false;
		}

	int result1 = 0;
	int result2 = 0;
	for(int i = 0; i < n; i++){
		int cnt1 = 0;
		int cnt2 = 0;

		for(int j = 0; j < n; j++){
			if (room[i][j] == true)
				cnt1++;
			else{
				if(cnt1 >= 2)
					result1++;
				cnt1 = 0;
			}

			if(room[j][i] == true)
				cnt2++;
			else{
				if(cnt2 >= 2)
					result2++;
				cnt2 = 0;
			}
		}

		if(cnt1 >= 2)
			result1++;
		if(cnt2 >= 2)
			result2++;
	}

	cout << result1 << ' ' << result2 << endl;


	return 0;
}
