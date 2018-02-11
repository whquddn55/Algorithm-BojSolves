#include <stdio.h>
int w, h, n, m;
int x[35000], y[35000], b[35000];
int min, max;
void divide(int m, int a[], int x1, int y1, int x2, int y2, int sw) {
	int i, l, r;
	int p = 0, cnt = 0x7fffffff;
	if (m == 0) {
		if (max<(x2 - x1)*(y2 - y1))max = (x2 - x1)*(y2 - y1);
		if (min>(x2 - x1)*(y2 - y1))min = (x2 - x1)*(y2 - y1);
		return;
	}
	for (i = 0; i<m; i++)
		if (cnt>a[i]) cnt = a[i], p = i;
	cnt = a[0], a[0] = a[p], a[p] = cnt;
	l = 1, r = m - 1;
	switch (sw) {
	case 0:
		while (l<m && y[a[l]]<y[a[0]])l++;
		while (r >= 0 && y[a[r]]>y[a[0]])r--;
		while (l<r) {
			while (l<m && y[a[l]]<y[a[0]])l++;
			while (r >= 0 && y[a[r]]>y[a[0]])r--;
			if (l >= r)break;
			cnt = a[l], a[l] = a[r], a[r] = cnt;
		}
		divide(l - 1, a + 1, x1, y1, x2, y[a[0]], 1);
		divide(m - l, a + l, x1, y[a[0]], x2, y2, 1);
		break;
	case 1:
		while (l<m && x[a[l]]<x[a[0]])l++;
		while (r >= 0 && x[a[r]]>x[a[0]])r--;
		while (l<r) {
			while (l<m && x[a[l]]<x[a[0]])l++;
			while (r >= 0 && x[a[r]]>x[a[0]])r--;
			if (l >= r)break;
			cnt = a[l], a[l] = a[r], a[r] = cnt;
		}
		divide(l - 1, a + 1, x1, y1, x[a[0]], y2, 0);
		divide(m - l, a + l, x[a[0]], y1, x2, y2, 0);
		break;
	}
}
int main() {
	int i;
	scanf("%d%d", &w, &h);
	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		b[i] = i;
	}
	min = 0x7fffffff, max = 0x80000000;
	divide(n, b, 0, 0, w, h, 0);
	printf("%d %d", max, min);
	return 0;
}