#include<iostream>
#include<vector>
int n, m;
std::vector<int> visited(1001, 0);
std::vector<int> graph[1001];

void dfs(int x) {
	visited[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
		int k = graph[x][i];
		if (visited[k] == 0) {
			dfs(k);
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
			dfs(i);
			ans++;
		}
	}
	std::cout << ans;
}