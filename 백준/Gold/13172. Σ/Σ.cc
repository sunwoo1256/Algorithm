#include<iostream>

const int X = 1'000'000'007;
long long divide(long long b, int r) {
	if (r == 1) {
		return b % X;
	}
	long long p = divide(b, r / 2);
	if (r % 2 == 0) {
		return (p%X * p%X) % X;
	}
	else {
		return (b%X * p%X * p%X) % X;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	int m;
	std::cin >> m;
	long long a, b;
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		std::cin >> b >> a;
		sum += (a * divide(b, X-2))%X;
	}
	std::cout << sum%X;
}