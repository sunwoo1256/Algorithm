#include<iostream>
#include<vector>
#include<queue>
int n;
std::vector<std::vector<int>> graph(101, std::vector<int>(101, 0));
std::vector<std::vector<int>> visited(101, std::vector<int> (101,0));

void bfs(int i) {
	std::queue<int> q;
	q.push(i);

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int j = 1; j <= n; j++) {
			if (graph[k][j] == 1) {
				if (visited[i][j] == 0) {
					q.push(j);
					visited[i][j] = 1;
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << visited[i][j] << " ";
		}
		std::cout << '\n';
	}

}