#include<iostream>
#include<vector>

std::vector<std::vector<int>> paper(129, std::vector<int>(129, 0));
int blue = 0;
int white = 0;

void color(int x, int y, int k) {	//(시작x, 시작y, 크기)
	bool cut = false;
	int first_color = paper[y][x];
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (paper[i][j] != first_color) {
				cut = true;
				break;
			}
		}
	}
	if (cut) {
		color(x, y, k / 2);
		color(x + k / 2, y, k / 2);
		color(x, y + k / 2, k / 2);
		color(x + k / 2, y + k / 2, k / 2);
	}
	else {
		if (first_color == 1) {
			blue++;
		}
		else {
			white++;
		}
	}
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++ ) {
		for (int j = 1; j <= n; j++) {
			std::cin >> paper[i][j];
		}
	}
	color(1, 1, n);
	
	std::cout << white << '\n';
	std::cout << blue;
}