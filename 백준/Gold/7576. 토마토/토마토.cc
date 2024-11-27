#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
int m, n;
std::vector<std::vector<int>> graph(1001, std::vector<int>(1001, -1));
std::vector<std::pair<int, int>> tomato;
std::vector<std::vector<int>> visited(1001, std::vector<int>(1001, 0));
int dx[5] = { 0, 0, -1, 1 };
int dy[5] = { -1, 1, 0, 0 };

void bfs() {
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < tomato.size(); i++) {
		auto k = tomato[i];
		q.push(k);
		visited[k.first][k.second] = 1;
	}
	while (!q.empty()) {
		auto cur = q.front();
		//std::cout << cur.first << ' ' << cur.second << '\n';
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = cur.first + dy[i];
			int xx = cur.second + dx[i];
			
			if (xx > 0 && xx <= m && yy > 0 && yy <= n) {
				if (visited[yy][xx] == 0) {
					q.push({ yy,xx });
					visited[yy][xx] = visited[cur.first][cur.second] + 1;
				}
			}
		}
	}


}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> graph[i][j];
			if (graph[i][j] == 1) {
				tomato.push_back({ i,j });
			}
			if (graph[i][j] == -1) {
				visited[i][j] = -1;
			}
		}
	}
	bfs();
	int maxi = 0;
	bool inzero = false;
	for (int i = 1; i <= n; i++) {
		if (inzero) {
			break;
		}
		for (int j = 1; j <= m; j++) {
			//std::cout << visited[i][j];
			if (visited[i][j] == 0) {
				inzero = true;
				maxi = -1;
				break;
			}
			if (maxi < visited[i][j]) {
				maxi = visited[i][j];
			}
		}
		//std::cout << '\n';
	}

	if (inzero) {
		std::cout << -1;
	}
	else
	{
		std::cout << maxi - 1;

	}
	
}