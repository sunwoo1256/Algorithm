#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> v(100001, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
		v[i] += v[i - 1];
	}
	int i, j;
	for (int a = 0; a < m; a++) {
		std::cin >> i >> j;
		std::cout << v[j] - v[i-1] << '\n';
	}
}