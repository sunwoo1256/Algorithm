#include<iostream>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	int x, y;
	std::cin >> n >> x >> y;

	int a;
	int cnt = 0;
	long long length = 0;
	int space = y - x;
	for (int i = 0; i < n; i++) {
		
		std::cin >> a;
		
		cnt += a / x;
		if (a % x > space * (a / x)) {
			length += (a % x) - space * (a / x);
		}
		
	}
	std::cout << cnt << '\n';
	std::cout << length << '\n';
}