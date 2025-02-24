#include<iostream>
#include<algorithm>
#include<vector>

int n, m;
std::vector<int> v(10, 0);
std::vector<int> visited(10, 0);

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			std::cout << v[i] << " ";
		}
		std::cout << '\n';
		return;
	}

	for (int x = 1; x <= n; x++) {
		if (visited[x] == 0) {
			visited[x] = 1;
			v[cnt] = x;
			dfs(cnt + 1);
			visited[x] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> m;
	dfs(0);
}