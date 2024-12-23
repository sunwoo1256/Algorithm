#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

std::vector<int> graph[101];
int sum = 1000000;
int kevin = 101;


void bfs(int user) {
	std::vector<int> visited(101, 0);
	std::queue<int> q;
	int sum1 = 0;
	q.push(user);
	visited[user] = 1;

	while (!q.empty()) {
		int k = q.front();
		q.pop();

		for (int i = 0; i < graph[k].size(); i++) {
			if (visited[graph[k][i]] == 0) {
				q.push(graph[k][i]);
				visited[graph[k][i]] = visited[k] + 1;
				sum1 += visited[graph[k][i]];
			}
		}
	}
	if (sum1 < sum) {
		sum = sum1;
		kevin = user;
	}
	
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	
	int a, b;

	for (int i = 0; i < m; i++) {
		std::cin >> a >> b;
		if (std::find(graph[a].begin(), graph[a].end(), b) == graph[a].end()) {
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		std::sort(graph[i].begin(), graph[i].end());
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	std::cout << kevin;
	
}