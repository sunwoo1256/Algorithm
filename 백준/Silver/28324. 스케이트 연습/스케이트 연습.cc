#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> v(n+1, 0);
	std::vector<int> ans(n+1, 1);

	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	
	long long sum = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (v[i] < ans[i + 1] + 1) {
			ans[i] = v[i];
		}
		else {
			ans[i] = ans[i + 1] + 1;
		}
		sum += ans[i];
	}
	std::cout << sum;
}