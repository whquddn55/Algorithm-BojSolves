#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

string str;
stack<int> st;

int main() {
	cin >> str;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			t1++;
		else if (str[i] == ')')
			t1--;
		else if (str[i] == '[')
			t2++;
		else
			t2--;
	}
	if (t1 || t2) 
		str.clear();
	if (str[0] == '(')
		st.push(-2);
	else if (str[0] == '[')
		st.push(-3);
	else 
		str.clear();
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '(')
			st.push(-2);
		else if (str[i] == '[')
			st.push(-3);
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				st.pop();
				st.push(2);
			}
			else {
				int sum = 0;
				while (true) {
					int temp = st.top();
					st.pop();
					if (temp == -2)
						break;
					if (temp < 0) {
						sum = -1;
						if (!st.empty())
							st.top() = 0;
						break;
					}
					sum += temp;
				}
				if (sum == -1)
					break;

				st.push(sum * 2);
			}
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				st.pop();
				st.push(3);
			}
			else {
				int sum = 0;
				while (true) {
					int temp = st.top();
					st.pop();
					if (temp == -3)
						break;
					if (temp < 0) {
						sum = -1;
						if (!st.empty())
							st.top() = 0;
						break;
					}
					sum += temp;
				}
				if (sum == -1)
					break;

				st.push(sum * 3);
			}
		}
	}
	if ((st.size() == 0) || (st.top() <= 0))
		printf("0\n");
	else {
		int result = 0;
		while (!st.empty()) {
			result += st.top();
			st.pop();
		}
		printf("%d\n", result);
	}


	return 0;
}