
#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int r, c;
	int k;
	int br, bc;
	int sr, sc;
	int vec;
	std::vector<int> dx;
	std::vector<int> dy;
	std::cin >> r >> c;
	std::vector<std::vector<int>> graph(r + 2, std::vector<int>(c + 2, 0));
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> br >> bc;
		graph[br + 1][bc + 1] = 1;
	}
	std::cin >> sr >> sc;
	for (int i = 0; i < 4; i++) {
		std::cin >> vec;
		if (vec == 1) {
			dx.push_back(0);
			dy.push_back(-1);
		}
		else if (vec == 2) {
			dx.push_back(0);
			dy.push_back(1);
		}
		else if (vec == 3) {
			dx.push_back(-1);
			dy.push_back(0);
		}
		else if (vec == 4) {
			dx.push_back(1);
			dy.push_back(0);
		}
	}
	int kx = sc + 1;
	int ky = sr + 1;
	int xx = kx;
	int yy = ky;
	graph[ky][kx] = 1;
	int dir = 0;
	while (true) {
		if (xx != kx || yy != ky) {
			break;
		}
		for (int i = dir; i < dir+4; i++) {
			xx = kx + dx[i%4];
			yy = ky + dy[i%4];
			if (xx >= 1 && xx <= c && yy >= 1 && yy <= r) {
				if (graph[yy][xx] != 1) {
					graph[ky][kx] = 1;
					kx = xx;
					ky = yy;
					dir = i;
					//std::cout << ky << " " << kx<<'\n';
					break;
				}
			}
		}
	}
	std::cout << ky - 1 << " " << kx - 1;
}