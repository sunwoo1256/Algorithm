#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n + 1, 0);
	std::vector<int> dp1(n + 1, 0);
	std::vector<int> dp2(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}

	if (n == 1) {
		std::cout << v[1];
	}
	else if (n == 2) {
		std::cout << v[1] + v[2];
	}
	else {
		dp1[1] = v[1];
		dp2[1] = v[1];
		for (int i = 2; i <= n; i++) {
			dp1[i] = v[i] + std::max(dp1[i - 2], dp2[i - 2]);
			dp2[i] = v[i] + dp1[i - 1];
		}
		std::cout << std::max(dp2[n], dp1[n]);
	}
}