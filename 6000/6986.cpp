#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	vector <double> scores(N, 0);

	for (int i = 0; i<N; i++) {
		scanf("%lf", &scores[i]);
	}

	sort(scores.begin(), scores.end());

	double sum1 = 0;
	for (int i = K; i<N - K; i++)
		sum1 += scores[i];
	double ans1 = (double)sum1 / (N - 2 * K);
	printf("%.2f\n", ans1 + (1e-8));
	double sum2 = sum1 + (scores[K] * K) + (scores[N - K - 1] * K);
	double ans2 = (double)sum2 / N;
	printf("%.2f", ans2 + (1e-8));
	return 0;
}
