#include<iostream>
#include<algorithm>
#include<vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<long long> v(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end(), std::greater<long long>());

	long long left = 0;
	long long right = v[0];
	long long mid;
	
	while (left <= right) {
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] <= mid) {
				break;
			}
			sum += v[i] - mid;
		}
		if (sum < m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		//std::cout << left << ' ' << mid << ' ' << right << '\n';
	}
	std::cout << right;
}