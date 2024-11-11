#include<iostream>
#include<vector>
int m, n, k;
std::vector<std::vector<int>> graph(51, std::vector<int>(51, 0));

void dfs(int x, int y) {
	int dx[5] = { 0, 0, -1, 1 };
	int dy[5] = { -1, 1, 0, 0 };

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if (X >= 0 && X < m && Y >= 0 && Y < n && graph[Y][X] == 1) {
			graph[Y][X] = 0;
			dfs(X, Y);
		}
	}
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int ans = 0;
		std::cin >> m >> n >> k;
		

		for (int i = 0; i < k; i++) {
			int x, y;
			std::cin >> x >> y;
			graph[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 1) {
					graph[i][j] = 0;
					dfs(j, i);
					ans++;
					//std::cout << i << ' ' << j << '\n';
					//std::cout << ans << '\n';
				}
			}
		}

		std::cout << ans << '\n';
		
	}
}