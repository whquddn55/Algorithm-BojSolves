#include <cstdio>
int ca[26], cb[26];
char A[1005], B[1005];
int main() {
	while (gets(A)) {
		gets(B);
		for (int i = 0; A[i]; i++) ca[A[i] - 'a']++;
		for (int i = 0; B[i]; i++) cb[B[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			int k = ca[i]>cb[i] ? cb[i] : ca[i];
			for (int j = 1; j <= k; j++) printf("%c", ('a' + i));
			ca[i] = cb[i] = 0;
		}
		puts("");
	}
}