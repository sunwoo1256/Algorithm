#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

std::vector<std::vector<int>> graph(27, std::vector<int>(27, 0));
std::vector<std::vector<int>> visited(27, std::vector<int>(27, 0));
std::pair<int, int> cur;
std::vector<int> home;
int danji = 0;

void bfs() {
	int cnt = 1;
	int dx[5] = { 0,0,-1,1 };
	int dy[5] = { -1,1,0,0 };
	std::queue<std::pair<int,int>> q;
	q.push(cur);
	visited[cur.first][cur.second] = 1;

	while (!q.empty()) {
		auto k = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = k.second + dx[i];
			int yy = k.first + dy[i];

			if (visited[yy][xx] == 0) {
				visited[yy][xx] = 1;
				if (graph[yy][xx] == 1) {
					cnt++;
					q.push({ yy,xx });
					graph[yy][xx] = 0;
				}
			}
		}

	}
	home.push_back(cnt);
	danji++;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::string s;

	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		for (int j = 1; j <= n; j++) {
			if (s[j-1] == '1') {
				graph[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j]) {
				cur = { i,j };
				bfs();
			}
		}
	}
	std::sort(home.begin(), home.end());
	std::cout << danji << '\n';
	for (auto elem : home) {
		std::cout << elem << '\n';
	}
}