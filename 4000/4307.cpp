#include <iostream>
#include <algorithm>
using namespace std;

int getMinCase(const size_t* const antPos, size_t antSize, size_t stickLen);
int getMaxCase(const size_t* const antPos, size_t antSize, size_t stickLen);

int main() {
	size_t caseSize;
	cin >> caseSize;
	for (size_t i = 0; i < caseSize; i++) {
		size_t stickLen, antSize;
		cin >> stickLen >> antSize;

		size_t* const antPos = new size_t[antSize];
		for (size_t j = 0; j < antSize; j++)
			cin >> antPos[j];

		cout << getMinCase(antPos, antSize, stickLen) << ' ' << getMaxCase(antPos, antSize, stickLen) << endl;
	}
	
	return 0;
}

int getMinCase(const size_t* const antPos, size_t antSize, size_t stickLen) {
	size_t result = 0;
	for (size_t i = 0; i < antSize; i++){
		if (antPos[i] < stickLen / 2)
			result = max(result, antPos[i]);
		else 
			result = max(result, stickLen - antPos[i]);
	}

	return result;
}
int getMaxCase(const size_t* const antPos, size_t antSize, size_t stickLen) {
	size_t result = 0;
	for (size_t i = 0; i < antSize; i++) {
		if (antPos[i] < stickLen / 2)
			result = max(result, stickLen - antPos[i]);
		else
			result = max(result, antPos[i]);
	}

	return result;
}