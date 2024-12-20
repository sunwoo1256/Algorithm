#include<iostream>
#include<queue>
#include<vector>
#include<string>

std::vector<std::vector<char>> graph(601, std::vector<char>(601, 'X'));
std::vector<std::vector<int>> visited(601, std::vector<int>(601, 0));
std::pair<int, int> I;
int person = 0;

void bfs() {
	int dx[5] = { 0,0,-1,1 };
	int dy[5] = { -1,1,0,0 };
	std::queue<std::pair<int, int>> q;
	q.push(I);
	visited[I.first][I.second] = 1;

	while (!q.empty()) {
		auto k = q.front();
		//std::cout << k.first << k.second << '\n';
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = k.second + dx[i];
			int yy = k.first + dy[i];

			if (xx>0 && yy>0 && xx<=600 && yy<=600 && visited[yy][xx] == 0) {
				//std::cout << yy << ", " << xx << '\n';
				visited[yy][xx] = 1;
				if (graph[yy][xx] == 'P') {
					person++;
					q.push({ yy,xx });
				}
				else if (graph[yy][xx] == 'O') {
					q.push({ yy,xx });
				}
			}
		}
		
	}

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::string s;
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'I') {
				I = { i, j + 1 };
				s[j] = 'O';
			}
			graph[i][j + 1] = s[j];
			//std::cout << graph[i-1][j];
			
		}
		//std::cout << '\n';
	}
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			std::cout << graph[i][j];
		}
		std::cout << '\n';
	}*/
	bfs();
	if (person) {
		std::cout << person;
	}
	else {
		std::cout << "TT";
	}
}