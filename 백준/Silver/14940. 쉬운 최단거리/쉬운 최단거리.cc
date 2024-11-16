#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

int n, m;
std::vector<std::vector<int>> v(1001, std::vector<int>(1001, 0));
std::vector<std::vector<int>> graph(1001, std::vector<int>(1001, -1));

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs(int x, int y) {
	std::queue<std::pair<int,int>> q;
	q.push({ x,y });
	graph[y][x] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
				if (v[yy][xx] == 0) {
					graph[yy][xx] = 0;
				}
				else if (graph[yy][xx] == -1) {
					graph[yy][xx] = graph[cur.second][cur.first] + 1;
					q.push({ xx,yy });
				}
			}
		}
	}


}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> v[i][j];
			if (v[i][j] == 2) {
				x = j;
				y = i;
			}
		}
	}

	bfs(x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) {
				graph[i][j] = 0;
			}
			std::cout << graph[i][j] << ' ';
		}
		std::cout << '\n';
	}
}