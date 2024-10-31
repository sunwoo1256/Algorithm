#include<iostream>
#include<vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		v[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (v[i] > v[i - j * j] + 1) {
				v[i] = v[i - j * j] + 1;
			}
		}
	}
	std::cout << v[n];
}