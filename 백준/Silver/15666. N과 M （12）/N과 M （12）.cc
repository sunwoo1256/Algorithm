#include<iostream>
#include<vector>
#include<algorithm>

int n, m;
std::vector<int> v(9, 0);
std::vector<int> nums;
std::vector<int> visited(9, 0);

void dfs(int k, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			std::cout << v[i] << " ";
		}
		std::cout << '\n';
		return;
	}
	for (int x = k; x < nums.size(); x++) {
		v[cnt] = nums[x];
		dfs(x, cnt + 1);
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
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

	dfs(0, 0);
}