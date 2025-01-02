#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m, b;
	std::cin >> n >> m >> b;

	std::vector<int> v(250001, 0);

	for (int i = 0; i < n * m; i++) {
		std::cin >> v[i];
	}
	int min = 1280000000;
	int floor = 0;
	for (int i = 0; i <= 256; i++) {
		int inven = b;
		int time = 0;
		for (int j = 0; j < n * m; j++) {
			if (v[j] - i > 0) {
				time += 2 * (v[j] - i);
				inven += (v[j] - i);
			}
			else {
				time += i - v[j];
				inven -= i - v[j];
			}
		}
		if (min >= time && inven >= 0) {
			min = time;
			floor = i;
		}
	}
	std::cout << min << " " << floor;
}