#include<iostream>
#include<vector>
#include<queue>
#include<string>
int n;
int cnt = 0;
int rgbcnt = 0;
std::vector<std::vector<char>> graph(101, std::vector<char>(101, 'O'));
std::vector<std::vector<int>> visited(101, std::vector<int>(101, 0));
std::vector<std::vector<int>> colorvisited(101, std::vector<int>(101, 0));

void colorbfs(int i, int j) {
	char color = graph[i][j];
	int dx[5] = { 0,0,-1,1 };
	int dy[5] = { -1,1,0,0 };
	std::queue<std::pair<int, int>> q;
	q.push({ i,j });
	colorvisited[i][j] = 1;

	while (!q.empty()) {
		auto k = q.front();
		q.pop();
		
		for (int a = 0; a < 4; a++) {
			int xx = k.second + dx[a];
			int yy = k.first + dy[a];
			if (xx <= n && xx > 0 && yy <= n && yy > 0 && colorvisited[yy][xx] == 0) {
				if (color == 'R' || color == 'G') {
					if (graph[yy][xx] == 'R' || graph[yy][xx] == 'G') {
						q.push({ yy,xx });
						colorvisited[yy][xx] = 1;
					}
				}
				else if (color == 'B') {
					if (graph[yy][xx] == 'B') {
						q.push({ yy,xx });
						colorvisited[yy][xx] = 1;
					}
				}
			}
		}
	}
	rgbcnt++;
}

void bfs(int i, int j) {
	char color = graph[i][j];
	int dx[5] = { 0,0,-1,1 };
	int dy[5] = { -1,1,0,0 };
	std::queue<std::pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;

	while (!q.empty()) {
		auto k = q.front();
		q.pop();

		for (int a = 0; a < 4; a++) {
			int xx = k.second + dx[a];
			int yy = k.first + dy[a];
			if (xx <= n && xx > 0 && yy <= n && yy > 0 && visited[yy][xx] == 0) {
				if (color == graph[yy][xx]) {
					q.push({ yy,xx });
					visited[yy][xx] = 1;
				}
			}
		}
	}
	cnt++;
}

int main() {
	std::cin >> n;
	std::string s;
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		for (int j = 0; j < n; j++) {
			graph[i][j + 1] = s[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0) {
				bfs(i,j);
			}
			if (colorvisited[i][j] == 0) {
				colorbfs(i, j);
			}
		}
	}

	std::cout << cnt << ' ' << rgbcnt;
}