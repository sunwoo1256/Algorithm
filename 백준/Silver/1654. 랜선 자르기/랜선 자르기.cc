#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int k, n;
	std::cin >> k >> n;

	std::vector<long long> v(k, 0);
	for (int i = 0; i < k; i++) {
		std::cin >> v[i];
	}

	long long left = 1;
	long long right = *max_element(v.begin(), v.end());
	long long mid = (left + right) / 2;

	while (left <= right) {
		mid = (left + right) / 2;
		long long count = 0;
		for (int i = 0; i < v.size(); i++) {
			count += v[i] / mid;
		}
		if (count < n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		//std::cout << mid<<'\n';
	}
	std::cout << right;
}