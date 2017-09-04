#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 1000
using namespace std;

int n;

long long fact(int n){
    if(n == 1){
        return 1;
    }
    else if (n == 0){
        return 1;
    }
    long long ret = 1;
    for (int i = 2; i <= n; i++){
        ret *= i;
    }
    return ret;
}

void problem1(vector<int>& firstPermutation, long long int& num, const int idx){
    long long standard = fact(idx - 1);
    long long ans = (num - 1) / standard;
    if(num == 0){
        ans = 0;
    }

    printf("%d ", firstPermutation[ans]);
    num -= ans * standard;
    firstPermutation.erase(firstPermutation.begin() + ans);
}

void problem2(vector<int>& per){
    vector<int> firstPermutation(n);
    for(int i = 0; i < n; i++){
        firstPermutation[i] = i + 1;
    }

    long long result = 1;
    for(int i = 0; i < n; i++){
        long long standard = fact(n - i - 1);
        vector<int>::iterator seek = find(firstPermutation.begin(), firstPermutation.end(), per[i]);
        int idx = distance(firstPermutation.begin(), seek);

        result += idx * standard;
        firstPermutation.erase(seek);
    }
    printf("%lld\n", result);
}

int main() {
    int problem;
    scanf("%d %d", &n, &problem);

    if(problem == 1) {
        long long num;
        scanf("%lld", &num);

        vector<int> firstPermutation(n);
        for(int i = 0; i < n; i++){
            firstPermutation[i] = i + 1;
        }

        for(int i = n; i >= 1; i--){
            problem1(firstPermutation, num, i);
        }
    }
    else if (problem == 2) {
        vector<int> per(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &per[i]);
        }

        problem2(per);
    }

    

    

	return 0;
}

