#include<iostream>
#include<vector>
#include<algorithm>
int n, m;
std::vector<int> nums;
std::vector<int> v(9, 0);
std::vector<int> visited(10001, 0);

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			std::cout << v[i] << " ";
		}
		std::cout << '\n';
		return;
	}

	for (int x = 0; x < n; x++) {
		if (visited[nums[x]] == 0) {
			v[cnt] = nums[x];
			visited[nums[x]] = 1;
			dfs(cnt + 1);
			visited[nums[x]] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		nums.push_back(num);
	}
	
	std::sort(nums.begin(), nums.end());
	dfs(0);
}