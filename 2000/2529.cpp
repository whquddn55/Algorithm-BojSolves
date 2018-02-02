#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<char> arr;

int getSequence1(int idx) {
	int result = 0;
	while ((idx < n) && (arr[idx] == '<')) {
		result++;
		idx++;
	}
	return result;
}

int getSequence2(int idx) {
	int result = 0;
	while ((idx < n) && (arr[idx] == '>')) {
		result++;
		idx++;
	}
	return result;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf(" %c", &arr[i]);

	vector<int> result;
	int toPut = 9;
	for (int i = 0; i < n;) {
		if (arr[i] == '>') {
			result.push_back(toPut);
			toPut--;
			i++;
		}
		else {
			int sequence = getSequence1(i);
			toPut -= sequence;
			for (int num = toPut; num <= toPut + sequence; num++)
				result.push_back(num);

			i += sequence + 1;
			toPut--;
		}
	}
	if (result.size() != n + 1) {
		for (int i = toPut; result.size() != n + 1; i--)
			result.push_back(i);
	}

	for (int i = 0; i < result.size(); i++)
		printf("%d", result[i]);
	printf("\n");

	result.clear();
	toPut = 0;
	for (int i = 0; i < n;) {
		if (arr[i] == '<') {
			result.push_back(toPut);
			toPut++;
			i++;
		}
		else {
			int sequence = getSequence2(i);
			toPut += sequence;
			for (int num = toPut; num >= toPut - sequence; num--)
				result.push_back(num);

			i += sequence + 1;
			toPut++;
		}
	}

	if (result.size() != n + 1) {
		for (int i = toPut; result.size() != n + 1; i--)
			result.push_back(i);
	}

	for (int i = 0; i < result.size(); i++)
		printf("%d", result[i]);
	printf("\n");

	return 0;
}