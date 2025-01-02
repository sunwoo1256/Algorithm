#include<iostream>
#include<algorithm>

int gcd(int a, int b) {
	int r;
	while (1) {
		r = a % b;
		if (r == 0) {
			return b;
		}
		a = b;
		b = r;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, x, y;
		std::cin >> m >> n >> x >> y;

		int k = x;
		int ans = -1;
		int a = std::max(m, n);
		int b = std::min(m, n);
		int gc = gcd(a, b);
		while (k <= m * n / gc) {
			if ((k - y) % n == 0) {
				ans = k;
				break;
			}
			k += m;
		}
		std::cout << ans << '\n';
	}
}