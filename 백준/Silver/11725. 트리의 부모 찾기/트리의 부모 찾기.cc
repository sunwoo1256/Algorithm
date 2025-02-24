#include<iostream>
#include<vector>
int n;
std::vector<int> graph[100001];
std::vector<int> visited(100001, 0);

void dfs(int k) {
	for (int i = 0; i < graph[k].size(); i++) {
		if (visited[graph[k][i]] == 0) {
			visited[graph[k][i]] = k;
			dfs(graph[k][i]);
		}
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) {
		std::cout << visited[i] << '\n';
	}
}