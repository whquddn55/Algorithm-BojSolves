#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> lengths;

bool decide(int n, long long val) {
    long long ret = 0;
    int size = lengths.size();

    for(int i = 0; i < size; ++i){
        ret += (lengths[i] / val > 0 ? lengths[i] / val : 0);
        if(ret >= n)
            break;
    }

    return ret >= n;
}

void get(int n) {
    sort(lengths.begin(), lengths.end());
    long long low = 1, high = lengths.back();

    long long mid;
    while(low <= high){
        mid = (low + high) / 2;

        if(decide(n, mid) == true)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << high << endl;
}

int main() {
    int k, n;
    cin >> k >> n;

    while(k--){
        long long height;
        cin >> height;
        lengths.push_back(height);
    }

    get(n);

    return 0;
}

