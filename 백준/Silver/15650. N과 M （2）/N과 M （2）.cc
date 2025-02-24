#include<iostream>
#include<vector>
int n, m;
std::vector<int> v(9, 0);
std::vector<int> visited(9, 0);

void dfs(int k, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			std::cout << v[i] << " ";
		}
		std::cout << '\n';
		return;
	}

	for (int x = k+1; x <= n; x++) {
		if (visited[x] == 0) {
			v[cnt] = x;
			visited[x] = 1;
			dfs(x, cnt + 1);
			visited[x] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;

	dfs(0, 0);
}