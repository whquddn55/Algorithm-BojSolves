#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (auto& element : a)
		ans += element;
	return ans;
}
