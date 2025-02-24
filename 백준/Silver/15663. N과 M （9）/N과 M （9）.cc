#include<iostream>
#include<vector>
#include<algorithm>

int n, m;
std::vector<int> v(9,0);
std::vector<int> nums;
std::vector<int> visited(10001, 0);
std::vector<std::vector<int>> ans;

void dfs(int cnt) {
	if (cnt == m) {
		ans.push_back(v);
		return;
	}

	for (int x = 0; x < nums.size(); x++) {
		if (visited[x] == 0) {
			v[cnt] = nums[x];
			visited[x] = 1;
			dfs(cnt + 1);
			visited[x] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		nums.push_back(num);
	}
	std::sort(nums.begin(), nums.end());

	dfs(0);
	std::sort(ans.begin(), ans.end());
	auto newend = std::unique(ans.begin(), ans.end());
	ans.erase(newend, ans.end());
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < m; j++) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << '\n';
	}
}