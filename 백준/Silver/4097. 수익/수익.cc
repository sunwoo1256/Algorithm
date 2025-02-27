#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	
	while (std::cin >> n && n != 0) {
		std::vector<int> v(250001, 0);
		std::vector<int> dp(250001, -10001);
		for (int i = 0; i < n; i++) {
			int p;
			std::cin >> p;
			v[i] = p;
		}
		dp[0] = v[0];
		for (int i = 1; i < n; i++) {
			
			dp[i] = std::max(dp[i - 1] + v[i], v[i]);
			//std::cout<<i<<" " << dp[i] << '\n';
		}
		std::cout << *std::max_element(dp.begin(),dp.end()) << '\n';
	}
}