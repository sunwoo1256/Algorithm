#include<iostream>
#include<vector>

int main() {
	int t;
	std::cin >> t;
	std::vector<long long> v(101, 0);
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	v[3] = 1;
	v[4] = 2;

	int n;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		
		if (v[n] == 0) {
			for (int j = 5; j <= n; j++) {
				if (v[j] == 0) {
					v[j] = v[j - 1] + v[j - 5];
				}
			}
		}
		std::cout << v[n] << '\n';
	}
}