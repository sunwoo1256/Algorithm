#include<iostream>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	int t;
	int n, m, k, d;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::cin >> n >> m >> k >> d;

		int same = (m * m - m) * k * n / 2;
		int diff = (n * n - n) * m * m / 2;
		int b = d / (same + diff);
		int ans = -1;
		if (b != 0) {
			ans = (same + diff) * b;
		}
		
		std::cout << ans << '\n';
	}
}