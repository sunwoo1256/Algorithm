#include<iostream>
#include<vector>
#include<algorithm>
int n, m;

std::vector<int> v(9,0);
std::vector<int> nums;
std::vector<int> visited(9, 0);

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			std::cout << v[i] << " ";
		}
		std::cout << '\n';
		return;
	}

	int last = 0;
	for (int x = 0; x < nums.size(); x++) {
		if (visited[x] == 0 && last != nums[x]) {
			v[cnt] = nums[x];
			visited[x] = 1;
			last = v[cnt];
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
}