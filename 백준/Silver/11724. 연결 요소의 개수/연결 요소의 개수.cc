#include<iostream>
#include<vector>
#include<queue>
int n, m;
std::vector<int> visited(1001, 0);
std::vector<int> graph[1001];
std::queue<int> q;

void dfs(int x) {
	visited[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
		int k = graph[x][i];
		if (visited[k] == 0) {
			dfs(k);
		}
	}
}

void bfs(int x) {
	q.push(x);
	visited[x] = 1;

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < graph[k].size(); i++) {
			if (visited[graph[k][i]] == 0) {
				q.push(graph[k][i]);
				visited[graph[k][i]] = 1;
			}
		}
	}
}

int main() {
	std::cin >> n >> m;
	int u, v;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			//dfs(i);
			bfs(i);
			ans++;
		}
	}
	std::cout << ans;
}