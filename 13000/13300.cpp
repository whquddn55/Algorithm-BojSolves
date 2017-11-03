#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > student;

int main() {
	int n, k;
	cin >> n >> k;

	student.resize(7);
	for (int i = 1; i < 7; i++)
		student[i].resize(2, 0);

	while (n--) {
		int a, grade;
		cin >> a >> grade;
		student[grade][a]++;
	}


	int cnt = 0;
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 2; j++){
			cnt += (student[i][j] - 1) / k + 1;
			if (!student[i][j])
				cnt--;
		}
	}

	cout << cnt << endl;


	return 0;
}
