#include<iostream>

const int X = 1000000007;
long long divide(long long b, int r) {
	if (r == 1) {
		return b % X;
	}
	if (r % 2 == 0) {
		return divide((b%X * b%X) % X, r / 2) % X;
	}
	else {
		return (divide((b%X * b%X) % X, r / 2) * b) % X;
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