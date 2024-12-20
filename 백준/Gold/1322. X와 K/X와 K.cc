#include<iostream>

int main() {
	long long x, k;
	long long y = 0;
	std::cin >> x >> k;
	int kshift = 0;

	for (int i = 0; i < 64; i++) {
		if (!((x >> i) & 1ll)) {	//i번째 비트가 0이면
			if ((k >> kshift) & 1ll) { //kshift번째 비트가 1이면
				y = y | (1ll << i);
			}
			kshift++;
		}
	}
	std::cout << y;
}