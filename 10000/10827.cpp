#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> Data;

Data multiply(Data& s1, Data& s2) {
	Data result, strtmp;
	int size1 = s1.size();
	int size2 = s2.size();

	for (int i = size2 - 1; i >= 0; i--) {
		strtmp.clear();

		for (int j = 0; j < size2 - (i + 1); j++)
			strtmp.push_back(0);

		for (int j = size1 - 1; j >= 0; j--)
			strtmp.push_back(s1[j] * s2[i]);

		int tsize = strtmp.size();
		int resize = result.size();
		for (int i = 0; i < tsize; i++) {
			if (resize == 0) {
				result.push_back(strtmp[i]);
				continue;
			}
			if (i < tsize - resize) {
				result.push_back(strtmp[i]);
				continue;
			}
			result[i] += strtmp[i];
		}
	}

	int size = result.size();

	for (int i = 0; i < size ; i++) 
		if (result[i] >= 10) {
			if (i == size - 1) {
				result.push_back(result[i] / 10);
				result[i] %= 10;
				size++;
				break;
			}
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	reverse(result.begin(), result.end());

	return result;
}

class Bignum {
private:
	Data deci;
	int a;
	int n;
public:
	Bignum() { }
	Bignum(const string& data) {
		int size = data.size();
		for (int i = 0; i < size; i++) {
			if (data[i] == '.') {
				a = size - (i + 1);
				n = a;
				continue;
			}
			deci.push_back(data[i] - '0');
		}
	}

	void power(int b) {
		Data tmp = deci;
		while (--b) {
			deci = multiply(deci, tmp);
			n += a;
		}
	}

	friend ostream& operator<< (ostream& os, Bignum& big);
};

ostream& operator<< (ostream& os, Bignum& big) {
	int size = big.deci.size();

	for (int i = 0; i < size; i++) {
		if (i == size -big.n)
			os << '.';
		os << big.deci[i];
	}
	
	os << endl;
	return os;
}

void get(Bignum& num, int b) {
	num.power(b);
	cout << num << endl;
}

int main() {
	string a;
	int b;
	cin >> a >> b;

	Bignum num(a);

	get(num, b);

	return 0;
}