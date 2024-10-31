#include<iostream>
#include<vector>
#include<cmath>
int main() {
	int n;
	std::cin >> n;

	std::vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
		for (int j = 1; j * j <= i; j++) {
			v[i] = v[i] < v[i - j * j] + 1 ? v[i] : v[i - j * j] + 1;
		}

	}
	std::cout << v[n];
}