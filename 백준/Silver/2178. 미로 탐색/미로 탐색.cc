#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

std::vector<std::vector<int>> graph(102, std::vector<int>(102, 0));
std::vector<std::vector<int>> visited(102, std::vector<int>(102, 0));

void bfs() {
	std::queue<std::pair<int,int>> q;
	int dx[5] = { 0,0,-1,1 };
	int dy[5] = { -1,1,0,0 };
	q.push({ 1,1 });
	visited[1][1] = 1;

	while (!q.empty()) {
		auto k = q.front();
		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int xx = k.second + dx[i];
			int yy = k.first + dy[i];

			if (visited[yy][xx] == 0) {
				if (graph[yy][xx] == 1) {
					q.push({ yy,xx });
					//std::cout << yy << " " << xx << '\n';
				}
				visited[yy][xx] = visited[k.first][k.second] + 1;
			}
		}
	}

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '1') {
				graph[i][j + 1] = 1;
			}
			else {
				graph[i][j + 1] = 0;
			}
		}
	}
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			std::cout << graph[i][j];
		}
		std::cout << '\n';
	}*/
	
	bfs();
	std::cout << visited[n][m];
}