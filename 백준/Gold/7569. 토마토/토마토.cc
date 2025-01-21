#include<iostream>
#include<vector>
#include<queue>
int m, n, h;
std::vector<std::vector<int>> tomato;
std::vector<std::vector<int>> graph(10001, std::vector<int>(101, -1));
std::vector<std::vector<int>> visited(10001, std::vector<int>(101, -1));

void bfs() {
	std::queue<std::vector<int>> q;
	int dx[7] = { -1,1,0,0,0,0 };
	int dy[7] = { 0,0,-1,1,0,0 };
	int dz[7] = { 0,0,0,0,-1,1 };

	for (int i = 0; i < tomato.size(); i++) {
		q.push(tomato[i]);
		visited[tomato[i][2] * n + tomato[i][0]][tomato[i][1]] = 1;
	}

	while (!q.empty()) {
		auto k = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int xx = k[1] + dx[i];
			int yy = k[0] + dy[i];
			int zz = k[2] + dz[i];

			if (xx >= 0 && xx < m && yy >= 0 && yy < n && zz >= 0 && zz < h) {
				if (visited[zz * n + yy][xx] == 0) {
					if (graph[zz * n + yy][xx] != -1) {
						q.push({ yy,xx,zz });
						//std::cout << yy << ' ' << xx << ' ' << zz << '\n';
						visited[zz * n + yy][xx] = visited[k[2] * n + k[0]][k[1]] + 1;
					}
					else {
						visited[zz * n + yy][xx] = 1;
					}
					
					//std::cout << "visited: " << visited[zz * n + yy][xx] << '\n';
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> m >> n >> h;
	for (int i = 0; i < n * h; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> graph[i][j];
			visited[i][j] = 0;
			if (graph[i][j] == 1) {
				tomato.push_back({ i%n,j, i/n }); //(y,x,z)
			}
			if (graph[i][j] == -1) {
				visited[i][j] = 1;
			}
		}
	}

	bfs();

	int max = 1;
	for (int i = 0; i < n * h; i++) {
		if (max == 0) {
			break;
		}
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				max = 0;
				break;
			}
			if (max < visited[i][j]) {
				max = visited[i][j];
			}
		}
	}
	std::cout << max - 1;
}