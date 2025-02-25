#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	

	std::vector<std::vector<int>> v(1025, std::vector<int>(1025,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> v[i][j];
			v[i][j] += v[i][j - 1];
		}
	}

	int x1, x2, y1, y2;
	for (int i = 0; i < m; i++) {
		int ans = 0;
		std::cin >> y1 >> x1 >> y2 >> x2;
		for (int y = y1; y <= y2; y++) {
			ans += v[y][x2] - v[y][x1-1];
		}
		std::cout << ans << '\n';
	}
}